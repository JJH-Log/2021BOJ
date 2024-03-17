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
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int f[5000], res;
string s;

int solve(string x) {
	int i, j, ans;
	ans = 0;
	for (i = 1, j = 0; i < x.size(); i++) {
		while (j && x[j] != x[i]) j = f[j - 1];
		if (x[i] == x[j]) f[i] = ++j;
		else f[i] = 0;
		ans = max(ans, f[i]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) res = max(res, solve(s.substr(i)));
	cout << res;

	return 0;
}