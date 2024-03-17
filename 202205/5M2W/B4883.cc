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

int N, v[100000][3];
lld dp[100000][3];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t_case = 1;
	while (true) {
		cin >> N;
		if (!N) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> v[i][j];
				dp[i][j] = 1e13;
			}
		}
		dp[0][1] = v[0][1];
		dp[0][2] = v[0][1] + v[0][2];
		for (int i = 1; i < N; i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][1];
			dp[i][1] = min(dp[i][1], dp[i - 1][2] + v[i][1]);
			dp[i][1] = min(dp[i][1], dp[i][0] + v[i][1]);
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][2];
			dp[i][2] = min(dp[i][2], dp[i][1] + v[i][2]);
		}
		cout << t_case << ". " << dp[N - 1][1] << '\n';
		t_case++;
	}

	return 0;
}