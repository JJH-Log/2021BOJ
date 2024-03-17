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

lld N, dp[101];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	iota(dp + 1, dp + 7, 1);
	for(int i = 7; i <= 100; i++) {
		for (int j = 3; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}
	cin >> N;
	cout << dp[N];
	
	return 0;
}