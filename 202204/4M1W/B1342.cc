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

int v[26], res;
string s;

void solve(int cnt, int before) {
	if (cnt == s.size()) {
		res++;
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (!v[i] || i == before) continue;
		v[i]--;
		solve(cnt + 1, i);
		v[i]++;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (auto c : s) v[c - 'a']++;
	solve(0, -1);
	cout << res;

	return 0;
}