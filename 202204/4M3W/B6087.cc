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

int N, M, v[100][100];
int vtd[100][100];
vector<pos> S;
string s;
queue<pos> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '*') v[i][j] = 1;
			if (s[j] == 'C') S.push_back({ i, j });
		}
	}
	vtd[S[0].x][S[0].y] = 1;
	q.push({ S[0].x, S[0].y });
	
	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int j = 1;
			while (true) {
				int dx = now.x + ("2011"[i] - '1') * j;
				int dy = now.y + ("1120"[i] - '1') * j;
				if (!inRange(dx, dy) || v[dx][dy] || (vtd[dx][dy] && vtd[dx][dy] < vtd[now.x][now.y] + 1)) break;
				vtd[dx][dy] = vtd[now.x][now.y] + 1;
				q.push({ dx, dy });
				j++;
			}
		}
	}
	cout << vtd[S[1].x][S[1].y] - 2;

	return 0;
}