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

int H, Y, res;
int dp[15];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> H >> Y;
	dp[0] = H;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i + (2 * j + 1)] = max(dp[i + (2 * j + 1)], dp[i] + dp[i] * (3 * j + 1) / 20);
		}
	}
	cout << dp[Y];
	
	return 0;
}