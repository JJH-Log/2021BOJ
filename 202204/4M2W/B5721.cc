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
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


void solve(int N, int M) {
	vector<vector<int>> v;
	vector<vector<int>> dp;
	vector<int> dp2;

	v.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}

	dp.resize(N, vector<int>(M, -1e9));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j] = v[i][j];
			if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (j > 1) dp[i][j] = max(dp[i][j], dp[i][j - 2] + v[i][j]);
		}
	}

	dp2.resize(N);
	for (int i = 0; i < N; i++) {
		dp2[i] = dp[i][M - 1];
		if (i) dp2[i] = max(dp2[i], dp2[i - 1]);
		if (i > 1) dp2[i] = max(dp2[i], dp2[i - 2] + dp[i][M - 1]);
	}
	
	cout << dp2[N - 1] << '\n';
	for (int i = 0; i < N; i++) dp[i].clear();
	dp2.clear();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		int N, M;
		cin >> N >> M;
		if (!N) break;
		solve(N, M);
	}

	return 0;
}