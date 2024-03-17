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

int t, sz, SA[MAXN], g[MAXN], tg[MAXN], LCP[MAXN], r[MAXN];
char s[MAXN];

bool suffix_cmp(int x, int y) {
	if (g[x] != g[y]) return g[x] < g[y];
	int xi = x + t < sz ? g[x + t] : -1;
	int yi = y + t < sz ? g[y + t] : -1;
	return xi < yi;
}

void SuffixArrayLCP()
{
	t = 1;
	for (int i = 0; i < sz; i++) {
		SA[i] = i;
		g[i] = s[i];
	}
	for (t = 1; t <= sz; t <<= 1) {
		sort(SA, SA + sz, suffix_cmp);
		tg[SA[0]] = 0;
		for (int i = 1; i < sz; i++) tg[SA[i]] = tg[SA[i - 1]] + suffix_cmp(SA[i - 1], SA[i]);
		for (int i = 0; i < sz; i++) g[i] = tg[i];
	}
	int len = 0;
	for (int i = 0; i < sz; i++) {
		if (g[i] == 0) {
			LCP[g[i]] = 0;
			continue;
		}
		while ((i + len < sz) && (SA[g[i] - 1] + len < sz) && s[i + len] == s[SA[g[i] - 1] + len]) len++;
		LCP[g[i]] = len;
		len = max(0, len - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	sz = strlen(s);
	SuffixArrayLCP();
	lld res = 0;
	for (int i = 0; i < sz; i++) res += sz - SA[i] - LCP[i];
	cout << res;

	return 0;
}