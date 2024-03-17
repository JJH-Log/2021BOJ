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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int res, x, y;
vector<pii> v;
int dp[1001][16][16];

void solve(int w, int ws, int b, int bs, int idx) {

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> x >> y;
		if (cin.eof()) break;
		v.push_back({ x, y });
	}
	for(int t = 0; t <= v.size(); t++) for (int i = 0; i <= 15; i++) for (int j = 0; j <= 15; j++) dp[t][i][j] = -1;
	dp[0][0][0] = 0;

	for (int t = 1; t <= v.size(); t++) {
		for (int i = 0; i <= 15; i++) {
			for (int j = 0; j <= 15; j++) {
				if (dp[t - 1][i][j] == -1) continue;
				dp[t][i][j] = max(dp[t][i][j], dp[t - 1][i][j]);
				if(i != 15) dp[t][i + 1][j] = max(dp[t][i + 1][j], dp[t - 1][i][j] + v[t - 1].first);
				if(j != 15) dp[t][i][j + 1] = max(dp[t][i][j + 1], dp[t - 1][i][j] + v[t - 1].second);
			}
		}
	}
	cout << dp[v.size()][15][15];
	
	return 0;
}