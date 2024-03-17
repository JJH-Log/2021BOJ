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
	int x, y;
};

struct info {
	int x, y, d;
};

struct cmp {
	bool operator()(info& A, info& B) {
		return A.d > B.d;
	}
};

int N, W;
pos w[1000];
bool v[1000][1000];
int t[1000][1000];
int dist[1000][1000];
int x, y;
queue<pos> q;
priority_queue<info, vector<info>, cmp> pq;

bool inRange(int x, int y) { return x >= 0 && x < N&& y >= 0 && y < N; }

void bfs() {
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && !t[dx][dy]) {
				t[dx][dy] = t[now.x][now.y] + 1;
				q.push({ dx, dy });
			}
		}
	}
}

void dijkstra() {
	while (!pq.empty()) {
		info now = pq.top();
		//cout << "NOW : " << now.x << ' ' << now.y << ' ' << now.d << '\n';
		pq.pop();
		if (dist[now.x][now.y] != now.d) continue;
		for (int i = 0; i < 8; i++) {
			int dx = now.x + "20112200"[i] - '1';
			int dy = now.y + "11202002"[i] - '1';
			if (inRange(dx, dy) && v[dx][dy]) {
				int ans = max(dist[now.x][now.y], t[dx][dy]);
				if (dist[dx][dy] == 0 || dist[dx][dy] > ans) {
					dist[dx][dy] = ans;
					pq.push({ dx, dy, dist[dx][dy] });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	cin >> N >> W;
	for (int i = 0; i < W; i++) {
		cin >> x >> y;
		x--, y--;
		t[x][y] = 1, q.push({ x, y });
	}
	bfs();
	t[0][0] = t[N - 1][N - 1] = 1;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) v[i][j] = (s[j] == '1');
	}
	dist[0][0] = 1;
	pq.push({ 0, 0, dist[0][0] });
	dijkstra();
	cout << dist[N - 1][N - 1] - 1;

	return 0;
}