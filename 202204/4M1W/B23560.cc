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
#define MOD 1000000007
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, dp[45][45][45];

int solve(int day, int l, int r) {
	if (l > r) return 1;
	int& res = dp[day][l][r];
	if (res != -1) return res;
	res = 0;
	if (day % 3 == 1) {
		if (l % 3 == 1) res += solve(day + 1, l + 1, r);
		if (r % 3 == 1) res += solve(day + 1, l, r - 1);
	}
	else {
		if (l % 3 != 1) res += solve(day + 1, l + 1, r);
		if (r % 3 != 1) res += solve(day + 1, l, r - 1);
	}
	return res;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 3 * N; i++) {
		for (int j = 0; j < 3 * N; j++) {
			for (int k = 0; k < 3 * N; k++) dp[i][j][k] = -1;
		}
	}
	solve(0, 0, 3 * N - 1);
	cout << (dp[0][0][3 * N - 1] / 2);

	return 0;
}