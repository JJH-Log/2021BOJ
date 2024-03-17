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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, L[101], J[101];
int dp[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i];
	for (int i = 1; i <= N; i++) cin >> J[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 99; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (j - L[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - L[i]] + J[i]);
		}
	}
	cout << dp[N][99];
	
	return 0;
}