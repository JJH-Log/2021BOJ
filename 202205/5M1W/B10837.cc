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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int K, C, M, N;
int dp[1001][1001];

int solve(int a, int b) {
	int& res = dp[a][b];
	if (res != -1) return res;
	int x, y;
	x = y = 0;
	for (int t = 0; t < K; t++) {
		if (x < a) x++;
		if (x == a && y == b) return res = 1;
		if (x > y + K - t || x + K - t - 1 < y) return res = 0;
		
		if (y < b) y++;
		if (x == a && y == b) return res = 1;
		if (x > y + K - t - 1 || x + K - t - 1 < y) return res = 0;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> K >> C;
	for (int i = 0; i <= 1000; i++) fill(dp[i], dp[i] + 1001, -1);
	for (int i = 0; i < C; i++) {
		cin >> M >> N;
		cout << solve(M, N) << '\n';
	}

	return 0;
}