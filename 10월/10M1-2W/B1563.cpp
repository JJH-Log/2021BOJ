#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int dp[1001][2][3];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dp[0][0][0] = dp[0][1][0] = dp[0][0][1] = 1;

	for (int i = 1; i < N; i++) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
		dp[i][1][1] = dp[i - 1][1][0];
		dp[i][1][2] = dp[i - 1][1][1];
	}
	cout << (dp[N - 1][0][0] + dp[N - 1][0][1] + dp[N - 1][0][2] + dp[N - 1][1][0] + dp[N - 1][1][1] + dp[N - 1][1][2]) % MOD;



	return 0;
}