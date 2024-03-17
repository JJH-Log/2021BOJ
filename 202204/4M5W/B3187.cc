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
#define MOD 86400
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

int R, C, res[2];
string v[250];
bool vtd[250][250];
queue<pos> q;

bool inRange(int x, int y) { return (x >= 0) && (x < R) && (y >= 0) && (y < C); }

int check(int x, int y) { return (v[x][y] == 'v'); }

void bfs(int x, int y) {
	int ans[2] = { 0, };
	vtd[x][y] = true;
	q.push({ x, y });
	if (v[x][y] != '.') ans[check(x, y)]++;

	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && v[dx][dy] != '#' && !vtd[dx][dy]) {
				if (v[dx][dy] != '.') ans[check(dx, dy)]++;
				vtd[dx][dy] = true;
				q.push({ dx, dy });
			}
		}
	}
	if (ans[0] > ans[1]) res[0] += ans[0];
	else res[1] += ans[1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> v[i];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (v[i][j] != '#' && !vtd[i][j]) bfs(i, j);
		}
	}
	cout << res[0] << ' ' << res[1];
	
	return 0;
}
