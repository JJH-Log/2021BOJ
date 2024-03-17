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

int N, M, T, D;
int h[25][25];
string s;

int dist[25][25];
priority_queue<pii, vector<pii>, greater<pii>> pq;

bool inRange(int x, int y) {
	return (x >= 0) && (x < N) && (y >= 0) && (y < M);
}

int decode(char x) {
	if (x >= 'A' && x <= 'Z') return x - 'A';
	else return x - 'a' + 26;
}

int dijkstra(int sx, int sy) {
	int d[25][25];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) d[i][j] = 1e9;
	}
	d[sx][sy] = 0;
	pq.push({ d[sx][sy], 25 * sx + sy });
	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();
		int x = now.second / 25;
		int y = now.second % 25;
		if (now.first != d[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int dx = x + "2011"[i] - '1';
			int dy = y + "1120"[i] - '1';
			if (inRange(dx, dy) && (abs(h[dx][dy] - h[x][y]) <= T)) {
				int cost = h[dx][dy] <= h[x][y] ? 1 : (h[dx][dy] - h[x][y]) * (h[dx][dy] - h[x][y]);
				if (d[dx][dy] > d[x][y] + cost) {
					d[dx][dy] = d[x][y] + cost;
					pq.push({ d[dx][dy], 25 * dx + dy });
				}
			}
		}
	}
	return d[0][0];
}
int res = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			h[i][j] = decode(s[j]);
			dist[i][j] = 1e9;
		}
	}
	dist[0][0] = 0;
	pq.push({ dist[0][0], 0 });
	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();
		int x = now.second / 25;
		int y = now.second % 25;
		if (now.first != dist[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int dx = x + "2011"[i] - '1';
			int dy = y + "1120"[i] - '1';
			if (inRange(dx, dy) && (abs(h[dx][dy] - h[x][y]) <= T)) {
				int cost = h[dx][dy] <= h[x][y] ? 1 : (h[dx][dy] - h[x][y]) * (h[dx][dy] - h[x][y]);
				if (dist[dx][dy] > dist[x][y] + cost) {
					dist[dx][dy] = dist[x][y] + cost;
					pq.push({ dist[dx][dy], 25 * dx + dy });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] + dijkstra(i, j) <= D) res = max(res, h[i][j]);
		}
	}
	cout << res;
	return 0;
}