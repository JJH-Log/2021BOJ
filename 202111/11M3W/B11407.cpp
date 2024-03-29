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
#define MOD 9901
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, M;
int dp[14 * 14][(1 << 14)];

int solve(int now, int status) {
	if (now >= N * M) {
		if (now == N * M && status == 0) return 1;
		return 0;
	}
	int& ret = dp[now][status];
	if (ret != -1) return ret;
	ret = 0;

	if (status & 1) ret += solve(now + 1, status >> 1);
	else {
		if (now % M != (M - 1) && (status & (1 << 1)) == 0) ret += solve(now + 2, status >> 2);
		ret += solve(now + 1, (status >> 1) | (1 << (M - 1)));
	}
	ret %= MOD;
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	cout << solve(0, 0);
	return 0;
}
