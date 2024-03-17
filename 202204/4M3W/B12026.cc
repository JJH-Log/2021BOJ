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

int N, v[1000];
int dp[1000];
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'B') v[i] = 0;
		if (s[i] == 'O') v[i] = 1;
		if (s[i] == 'J') v[i] = 2;
	}
	for (int i = 1; i < N; i++) dp[i] = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[j] == ((v[i] + 1) % 3)) dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
		}
	}
	if (dp[N - 1] == 1e9) cout << -1;
	else cout << dp[N - 1];


	return 0;
}