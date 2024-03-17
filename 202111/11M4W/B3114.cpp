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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


int v[1500][1500];
int a[1501][1501], b[1501][1501];//reversed prefix sum
int dp[1500][1500];
int R, C;


int ctoi(char c) { return c - '0'; }

int parse(string s) {
	if (s.size() == 2) return ctoi(s[1]);
	else return 10 * ctoi(s[1]) + ctoi(s[2]);
}

int solve(int x, int y) {
	int ans = 0;
	if (dp[x][y]) return dp[x][y];
	if (x != R - 1) ans = max(ans, solve(x + 1, y) + b[x][y + 1]);
	if (y != C - 1) ans = max(ans, solve(x, y + 1) + a[x + 1][y]);
	if (x != R - 1 && y != C - 1) ans = max(ans, solve(x + 1, y + 1) + a[x + 1][y] + b[x][y + 1]);
	return dp[x][y] = ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			string s;
			cin >> s;
			if (s[0] == 'A') v[i][j] = parse(s);
			else v[i][j] = -parse(s);
		}
	}
	for (int j = 0; j < C; j++) if (v[R - 1][j] > 0) a[R - 1][j] = v[R - 1][j];
	for (int i = R - 2; i >= 0; i--) {
		for (int j = 0; j < C; j++) {
			a[i][j] = a[i + 1][j];
			if (v[i][j] > 0) a[i][j] += v[i][j];
		}
	}
	for (int i = 0; i < R; i++) if (v[i][C - 1] < 0) b[i][C - 1] = -v[i][C - 1];
	for (int j = C - 2; j >= 0; j--) {
		for (int i = 0; i < R; i++) {
			b[i][j] = b[i][j + 1];
			if (v[i][j] < 0) b[i][j] -= v[i][j];
		}
	}
	cout << solve(0, 0);
	return 0;
}
