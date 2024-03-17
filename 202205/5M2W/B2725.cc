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
#define MOD 1000000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int T, N;
int dp[1001];

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fill(dp, dp + 1001, -1);
	dp[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		dp[i] = dp[i - 1];
		for (int j = 1; j < i; j++) if (gcd(i, j) == 1) dp[i] += 2;
	}

	cin >> T;
	while(T--){
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}