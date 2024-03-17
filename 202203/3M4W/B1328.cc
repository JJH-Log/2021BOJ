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

lld dp[101][101][101];
int T;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	dp[1][1][1] = 1;
	for (int n = 2; n <= 100; n++) {
		for (int t = 2; t <= n + 1; t++) {
			for (int i = 1; i < t; i++) {
				int x = i;
				int y = t - i;
				if (x) dp[n][x][y] = (dp[n][x][y] + dp[n - 1][x - 1][y]) % MOD;
				if (y) dp[n][x][y] = (dp[n][x][y] + dp[n - 1][x][y - 1]) % MOD;
				dp[n][x][y] = (dp[n][x][y] + dp[n - 1][x][y] * (n - 2)) % MOD;
			}
		}
	}
	int n, l, r;
	cin >> n >> l >> r;
	cout << dp[n][l][r];
	
	return 0;
}