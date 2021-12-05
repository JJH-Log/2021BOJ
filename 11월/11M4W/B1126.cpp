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
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[50];
int dp[50][500001]; //j : 높이 차
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) cin >> v[i], dp[i][0] = 0;
	dp[0][v[0]] = v[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 500000; j++) {
			if (dp[i - 1][j] != -1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				dp[i][j + v[i]] = max(dp[i][j + v[i]], dp[i - 1][j] + v[i]);
				if (j >= v[i]) dp[i][j - v[i]] = max(dp[i][j - v[i]], dp[i - 1][j]);
				else dp[i][v[i] - j] = max(dp[i][v[i] - j], dp[i - 1][j] + v[i] - j);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) result = max(result, dp[i][0]);
	if (!result) cout << -1;
	else cout << result;
	return 0;
}
