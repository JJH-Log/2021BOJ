#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1234567
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int x, y;
	bool used;
};

int N, M;
int v[1000][1000];
int vtd[2][1000][1000];
bool line_vtd[2][1000];
int r1, c1, r2, c2;
queue<info> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> r1 >> c1 >> r2 >> c2;
	r1--, c1--, r2--, c2--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}
	vtd[0][r1][c1] = 1;
	q.push({ r1, c1, false });

	while (!q.empty()) {
		info now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + ("2011"[i] - '1') * v[now.x][now.y];
			int dy = now.y + ("1120"[i] - '1') * v[now.x][now.y];
			if (inRange(dx, dy) && !vtd[now.used][dx][dy]) {
				vtd[now.used][dx][dy] = vtd[now.used][now.x][now.y] + 1;
				q.push({ dx, dy, now.used });
			}
		}
		if (!now.used) {
			if (!line_vtd[0][now.y]) {
				line_vtd[0][now.y] = true;
				for (int i = 0; i < N; i++) {
					if (!vtd[1][i][now.y]) {
						vtd[1][i][now.y] = vtd[0][now.x][now.y] + 1;
						q.push({ i, now.y, true });
					}
				}
			}
			if (!line_vtd[1][now.x]) {
				line_vtd[1][now.x] = true;
				for (int j = 0; j < M; j++) {
					if (!vtd[1][now.x][j]) {
						vtd[1][now.x][j] = vtd[0][now.x][now.y] + 1;
						q.push({ now.x, j, true });
					}
				}
			}
		}
	}
	if (!vtd[0][r2][c2] && !vtd[1][r2][c2]) cout << -1;
	else if (!vtd[0][r2][c2]) cout << vtd[1][r2][c2] - 1;
	else if (!vtd[1][r2][c2]) cout << vtd[0][r2][c2] - 1;
	else cout << min(vtd[0][r2][c2], vtd[1][r2][c2]) - 1;

	return 0;
}