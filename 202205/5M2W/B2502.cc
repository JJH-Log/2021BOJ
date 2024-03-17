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

lld dp[31][2];
lld A, B, D, K;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	dp[0][0] = dp[1][1] = 1;
	for (int i = 2; i < 30; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	cin >> D >> K; D--;
	A = 1;
	while (true) {
		if ((K - dp[D][0] * A) % dp[D][1] == 0) {
			cout << A << '\n' << ((K - dp[D][0] * A) / dp[D][1]);
			return 0;
		}
		A++;
	}

	return 0;
}