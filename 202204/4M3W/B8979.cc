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

struct info {
	int idx, g, s, b;
};

bool _same(info x, info y) {
	return ((x.g == y.g) && (x.s == y.s) && (x.b == y.b));
}
bool compare(info x, info y) {
	if (x.g == y.g) {
		if (x.s == y.s) return x.b > y.b;
		return x.s > y.s;
	}
	return x.g > y.g;
}

int N, M;
info v[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> v[i].idx >> v[i].g >> v[i].s >> v[i].b;
	sort(v + 1, v + N + 1, compare);

	int j = 1;
	for (int i = 1; i <= N; i++){
		if (!_same(v[i - 1], v[i])) j = i;
		if (v[i].idx == M) {
			cout << j;
			return 0;
		}
	}

	return 0;
}