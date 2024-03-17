#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y;
};

int v[100][100], N, cost[100][100], res;
bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }
queue<pos> q;


bool isAble(int b1, int b2) {
	bool vtd[100][100] = { 0, };
	if (v[0][0] < b1 || v[0][0] > b2) return false;
	q.push({ 0, 0 }); vtd[0][0] = true;
	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && !vtd[dx][dy] && v[dx][dy] >= b1 && v[dx][dy] <= b2) {
				vtd[dx][dy] = true;
				q.push({ dx, dy });
			}
		}
	}
	return vtd[N - 1][N - 1];
}


int sol(int b1, int lo, int hi) {
	if (lo > hi) return 1e9;
	int mid = (lo + hi) / 2;
	if (isAble(b1, mid)) return min(mid, sol(b1, lo, mid - 1));
	else return sol(b1, mid + 1, hi);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	res = 1e9;
	for (int i = 0; i <= 200; i++) {
		int ans = sol(i, i, 200);
		if (ans == 1e9) continue;
		res = min(res, ans - i);
	}
	cout << res;

	return 0;
}
