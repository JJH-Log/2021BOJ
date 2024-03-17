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
#define MAXN 500005
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

/*
 Reference : https://jason9319.tistory.com/141
 Author : jason9319
*/

int t, SA[MAXN], g[MAXN], tg[MAXN], LCP[MAXN], r[MAXN];
string s;

bool suffix_cmp(int x, int y) {
	if (g[x] != g[y]) return g[x] < g[y]; 
	int xi = x + t < s.size() ? g[x + t] : -1;
	int yi = y + t < s.size() ? g[y + t] : -1;
	return xi < yi;
}

void SuffixArrayLCP()
{
	t = 1;
	int sz = s.size();
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
			LCP[g[i]] = -1;
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
    SuffixArrayLCP();
    for (int i = 0; i < s.size(); i++) cout << SA[i] + 1 << ' ';
	cout << "\nx ";
	for (int i = 1; i < s.size(); i++) cout << LCP[i] << ' ';
	return 0;
}
