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
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int dp[1000][1000];
string s1, s2, res;

int LCS(int x, int y) {
	if (x < 0 || y < 0) return 0;
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	if (s1[x] == s2[y]) return ret = LCS(x - 1, y - 1) + 1;
	else return ret = max(LCS(x - 1, y), LCS(x, y - 1));
}

void recon(int x, int y) {
	if (x < 0 || y < 0) return;
	if (s1[x] == s2[y]) {
		res += s1[x];
		recon(x - 1, y - 1);
	}
	else {
		int dp1 = (x > 0) ? dp[x - 1][y] : 0;
		int dp2 = (y > 0) ? dp[x][y - 1] : 0;
		(dp1 >= dp2) ? recon(x - 1, y) : recon(x, y - 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(dp, -1, sizeof(dp));
	cin >> s1 >> s2;
	cout << LCS(s1.size() - 1, s2.size() - 1) << '\n';
	recon(s1.size() - 1, s2.size() - 1);
	reverse(res.begin(), res.end());
	cout << res;

	return 0;
}
