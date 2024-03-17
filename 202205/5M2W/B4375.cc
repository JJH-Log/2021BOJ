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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, t, lft;
int dp[10001];

int solve(int X) {
	int& ans = dp[X];
	if (ans != -1) return ans;

	int t, left;
	t = 1, left = (1 % X);
	while (t++) {
		if (!left) return ans = t - 1;
		left = (left * 10 + 1) % X;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fill(dp, dp + 10001, -1);
	while (true) {
		cin >> N;
		if (cin.eof()) break;
		cout << solve(N) << '\n';
	}

	return 0;
}