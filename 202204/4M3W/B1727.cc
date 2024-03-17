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

int N, M, D, v[2][1000];
int dp[1000][1000], res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[0][i];
	for (int i = 0; i < M; i++) cin >> v[1][i];
	if (N < M) {
		swap(N, M);
		for (int i = 0; i < N; i++) swap(v[0][i], v[1][i]);
	}
	sort(v[0], v[0] + N);
	sort(v[1], v[1] + M);
	D = N - M; //diffrence

	for (int j = 0; j <= D; j++) dp[0][j] = abs(v[1][0] - v[0][j]);
	for (int i = 1; i < M; i++) {
		int best = dp[i - 1][0];
		for (int j = 0; j <= D; j++) {
			best = min(best, dp[i - 1][j]);
			dp[i][j] = best + abs(v[1][i] - v[0][i + j]);
		}
	}
	res = 2e9;
	for (int i = 0; i <= D; i++) res = min(res, dp[M - 1][i]);
	cout << res;

	return 0;
}