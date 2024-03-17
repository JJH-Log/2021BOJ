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


struct pool {
	lld s, e;
};

bool compare(pool a, pool b) {
	if (a.s == b.s) return a.e < b.e;
	return a.s < b.s;
}

lld N, L;
pool v[10000];
lld now, cnt, gap;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> v[i].s >> v[i].e;
	sort(v, v + N, compare);

	for (int i = 0; i < N; i++) {
		now = max(now, v[i].s);
		gap = v[i].e - now;
		cnt += (gap + L - 1) / L;
		now += (gap + L - 1) / L * L;
	}
	cout << cnt;


	return 0;
}