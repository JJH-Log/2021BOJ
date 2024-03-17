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

int N, res, dp[1 << 15][15], v[15][15];
string s;


void update(int N) {
	int ans = 0;
	while (N) {
		if (N % 2) ans++;
		N /= 2;
	}
	res = max(res, ans);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) v[i][j] = s[j] - '0';
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) dp[i][j] = 20;
	}
	dp[1][0] = 0;

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] != 20) {
				update(i);
				for (int k = 0; k < N; k++) {
					if ((i & (1 << k)) == 0 && v[j][k] >= dp[i][j]) {
						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], v[j][k]);
					}
				}
			}
		}
	}
	cout << res;

	
	return 0;
}