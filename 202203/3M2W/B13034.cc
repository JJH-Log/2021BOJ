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

int N, dp[1001];

int getGrundy(int X) {
	bitset<12> bs;
	for (int i = 0; i + 2 < X; i++) bs[dp[i] ^ dp[X - i - 2]] = 1;
	for (int i = 0; i < 30; i++) if (!bs[i]) return i;
	return -1;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	dp[0] = dp[1] = 0;
	dp[2] = 1;

	cin >> N;
	for (int i = 3; i <= N; i++) dp[i] = getGrundy(i);
	cout << (dp[N] ? 1 : 2);

	return 0;
}