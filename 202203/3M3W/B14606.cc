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
#include <numeric>
#define MOD 1000000007
#define BOUND 2000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 5005
using namespace std;

int N, dp[11];

int solve(int K) {
	int& res = dp[K];
	if (res != -1) return res;
	for (int i = 1; i <= (K / 2); i++) res = max(res, solve(i) + solve(K - i) + i * (K - i));
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(10);
	cout << fixed;

	memset(dp, -1, sizeof dp);
	dp[1] = 0;
	cin >> N;
	cout << solve(N);

	return 0;
}

