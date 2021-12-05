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

int v[1000];
int dp[1000][1000];
int N, T;

int solve(int l, int r, int turn) {
	if (l > r) return 0;
	if (dp[l][r]) return dp[l][r];
	if (turn % 2) return dp[l][r] = min(solve(l + 1, r, turn + 1), solve(l, r - 1, turn + 1));
	else return dp[l][r] = max(v[l] + solve(l + 1, r, turn + 1), v[r] + solve(l, r - 1, turn + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T;
	cin >> T;
	while (T--) {
		memset(v, 0, sizeof(v));
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) cin >> v[i];
		cout << solve(0, N - 1, 0) << '\n';
	}

	return 0;
}
