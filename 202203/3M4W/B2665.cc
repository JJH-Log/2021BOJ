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
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y, val;
};

struct cmp {
	bool operator()(pos a, pos b) {
		return a.val > b.val;
	}
};

int N, v[50][50], dist[50][50];
string s;
priority_queue<pos, vector<pos>, cmp> pq;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }

void dijkstra() {
	dist[0][0] = 0;
	pq.push({ 0, 0, 0 });

	while (!pq.empty()) {
		pos now = pq.top(); pq.pop();
		if (dist[now.x][now.y] != now.val) continue;
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && dist[dx][dy] > dist[now.x][now.y] + v[dx][dy]) {
				dist[dx][dy] = dist[now.x][now.y] + v[dx][dy];
				pq.push({ dx, dy, dist[dx][dy] });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '0') v[i][j] = 1;
			dist[i][j] = 1e9;
		}
	}
	dijkstra();
	cout << dist[N - 1][N - 1];

	return 0;
}