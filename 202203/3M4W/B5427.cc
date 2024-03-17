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


int N, M;
int d[2][1000][1000]; //0 : fire, 1 : me
int v[1000][1000];
pos S;
vector<pos> fire;
string s;
queue<pos> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }


void bfs(int o) {
	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && !v[dx][dy] && !d[o][dx][dy]) {
				d[o][dx][dy] = d[o][now.x][now.y] + 1;
				q.push({ dx, dy });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> M >> N;
		fire.clear();
		for (int i = 0; i < N; i++) {
			cin >> s;
			for (int j = 0; j < M; j++) {
				if (s[j] == '@') S = { i, j };
				if (s[j] == '*') fire.push_back({ i, j });
				if (s[j] == '#') v[i][j] = 1;
				else v[i][j] = 0;
				d[0][i][j] = d[1][i][j] = 0;
			}
		}

		for (auto tmp : fire) {
			d[0][tmp.x][tmp.y] = 1;
			q.push({ tmp.x, tmp.y });
		}
		bfs(0);

		d[1][S.x][S.y] = 1;
		q.push({ S.x, S.y });
		bfs(1);

		int res = 1e9;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
					if (d[1][i][j]) {
						if (!d[0][i][j] || (d[0][i][j] > d[1][i][j])) res = min(res, d[1][i][j]);
					}
				}
			}
		}

		if (res == 1e9) cout << "IMPOSSIBLE\n";
		else cout << res << '\n';
	}

	return 0;
}