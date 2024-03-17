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

pii v[4];
lld d[6];


lld dist(pii x, pii y) { return (lld)(x.first - y.first) * (x.first - y.first) + (lld)(x.second - y.second) * (x.second - y.second); }



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 4; i++) cin >> v[i].first >> v[i].second;
		sort(v, v + 4);
		d[0] = dist(v[0], v[1]);
		d[1] = dist(v[0], v[2]);
		d[2] = dist(v[1], v[3]);
		d[3] = dist(v[2], v[3]);
		d[4] = dist(v[0], v[3]);
		d[5] = dist(v[1], v[2]);
		cout << ((d[0] == d[1]) && (d[1] == d[2]) && (d[2] == d[3]) && (d[4] == d[5])) << '\n';
	}

	return 0;
}