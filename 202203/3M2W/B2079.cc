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
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string s;
int N;
bool dp[2500][2500];
int res[2500];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	N = s.size();
	for (int i = 0; i < N; i++) dp[i][i] = 1;
	for (int g = 1; g < N; g++) {
		for (int i = 0; i + g < N; i++) {
			if (g == 1) dp[i][i + g] = (s[i] == s[i + g]);
			else dp[i][i + g] = dp[i + 1][i + g - 1] && (s[i] == s[i + g]);
		}
	}
	res[0] = 1;
	for (int i = 1; i < N; i++) {
		res[i] = (dp[0][i]? 1 : 1e9);
		for (int j = 0; j < i; j++) if (dp[j + 1][i]) res[i] = min(res[i], res[j] + 1);
	}
	cout << res[N - 1];

	return 0;
}
