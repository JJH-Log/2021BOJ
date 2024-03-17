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

lld N, v[2001], dp[6][2001];
lld m, M, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		dp[0][i] = dp[0][i - 1] + v[i];
	}
	
	M = 0;
	for (int i = 1; i <= N; i++) {
		dp[1][i] = dp[0][i] - M;
		M = max(M, dp[0][i]);
	}

	m = 0;
	for (int i = 1; i <= N; i++) {
		dp[2][i] = dp[0][i] - m;
		m = min(m, dp[1][i]);
	}

	M = 0;
	for (int i = 1; i <= N; i++) {
		dp[3][i] = dp[0][i] - M;
		M = max(M, dp[2][i]);
	}

	m = 0;
	for (int i = 1; i <= N; i++) {
		dp[4][i] = dp[0][i] - m;
		m = min(m, dp[3][i]);
	}


	for (int i = 1; i <= N; i++) res = max(res, dp[4][i]);
	cout << res;


	return 0;
}