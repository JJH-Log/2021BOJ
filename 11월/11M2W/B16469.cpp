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
#include <sstream>
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int R, C;
int v[100][100];
int w[3][100][100];
queue<pii> q;

void simul(int idx) {
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.first + "2011"[i] - '1';
			int dy = now.second + "1120"[i] - '1';
			if (dx >= 0 && dx < R && dy >= 0 && dy < C) {
				if (!w[idx][dx][dy] && !v[dx][dy]) {
					w[idx][dx][dy] = w[idx][now.first][now.second] + 1;
					q.push({ dx, dy });
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) v[i][j] = s[j] - '0';
	}

	int x, y;
	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		w[i][--x][--y] = 1;
		q.push({ x, y });
		simul(i);
	}

	int result, cnt;
	result = 11000, cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (w[0][i][j] && w[1][i][j] && w[2][i][j]) {
				int now = max(w[0][i][j], w[1][i][j]);
				now = max(now, w[2][i][j]);
				if (result > now) result = now, cnt = 1;
				else if (result == now) cnt++;
			}
		}
	}
	if (result == 11000) cout << -1;
	else cout << result - 1 << '\n' << cnt;

	return 0;
}
