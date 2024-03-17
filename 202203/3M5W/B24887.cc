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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, M;
lld v[200000];
lld dp[200000];
lld total;

bool check(int X) {
	fill(dp, dp + N, 0);
	for (int i = 0; i < N; i++) {
		dp[i] = v[i];
		if (i >= 1) dp[i] = max(dp[i], dp[i - 1]);
		if (i >= X) dp[i] = max(dp[i], dp[i - X] + v[i]);
	}
	return (dp[N - 1] >= M);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		total += v[i];
		if (v[i] >= M) {
			cout << "Free!";
			return 0;
		}
	}
	if (total < M) cout << -1;
	else {
		int lo, hi;
		lo = 0, hi = N;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (check(mid)) lo = mid;
			else hi = mid;
		}
		cout << lo - 1 << '\n';
	}


	return 0;
}