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
#define MAXN 200005
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld v[100][100], dp[100][100];
lld N;

lld solve(int x, int y) {
	if (x >= N || y >= N) return 0;
	lld& res = dp[x][y];
	if (res != -1) return res;
	if (v[x][y] == 0) return 0;
	return res = solve(x + v[x][y], y) + solve(x, y + v[x][y]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 100; i++) memset(dp[i], -1, sizeof(dp[i]));
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	dp[N - 1][N - 1] = 1;
	solve(0, 0);
	cout << dp[0][0];

	return 0;
}
