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
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#define MOD 1000000007
#define BOUND 1000000000
#define MAXN 200005
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int dp[50][1001];
int N, S;


int solve(int left, int point) {
	if (point > S) return 0;
	int& res = dp[left][point];
	if (left == 0) return res = (point == S);
	if (res != -1) return res;
	for (int i = 1; (res <= 0) && i <= left; i++) res = solve(left - i, point + (i * (i + 1)) / 2);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 50; i++) memset(dp[i], -1, sizeof(dp[i]));
	cin >> N >> S;
	solve(N - 2, 0);
	if (dp[0][S] == 1) cout << 1;
	else cout << 0;

	return 0;
}
