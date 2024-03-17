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

struct info {
	int K, S;
};

int N, T;
info v[100];
int dp[101][10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> v[i].K >> v[i].S;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= T; j++) {
			if (j < v[i].K) {
				if (i) dp[i][j] = dp[i - 1][j];
			}
			else {
				if (i) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].K] + v[i].S);
				else dp[i][j] = v[i].S;
			}
		}
	}
	cout << dp[N - 1][T];

	return 0;
}