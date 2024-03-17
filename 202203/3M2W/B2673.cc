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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
int dp[101][101];
int v[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[x][y] = v[y][x] = 1;
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = i; j > 0; j--) {
			for (int k = j; k < i; k++) {
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + v[j][i]);
			}
		}
	}
	cout << dp[1][100];
	

	return 0;
}