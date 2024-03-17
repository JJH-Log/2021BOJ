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

lld dp[1000][1000];

lld solve(int x, int y) {
	lld &res = dp[x][y];
	if (res != -1) return res;
	if (x == 0 && y == 0) return res = 1;
	res = 0;
	if (x) res = (res + solve(x - 1, y)) % MOD;
	if (y) res = (res + solve(x, y - 1)) % MOD;
	if (x && y) res = (res + solve(x - 1, y - 1)) % MOD;
	return res;
}


int N, M;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) fill(dp[i], dp[i] + M, -1);
	cout << solve(N - 1, M - 1);

	return 0;
}