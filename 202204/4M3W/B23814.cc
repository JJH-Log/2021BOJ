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

lld D, N, M, K;
pll tmp, res;

bool compare(pll x, pll y) {
	if (x.first == y.first) return x.second < y.second;
	return x.first < y.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> D >> N >> M >> K;
	N %= D, M %= D;
	res = { K / D, K };
	if (K >= (D - N)) {
		tmp = { 1 + (K - (D - N)) / D, (K - (D - N)) };
		if (compare(res, tmp)) res = tmp;
	}
	if (K >= (D - M)) {
		tmp = { 1 + (K - (D - M)) / D, (K - (D - M)) };
		if (compare(res, tmp)) res = tmp;
	}
	if (K - D >= D - N - M) {
		tmp = { 2 + (K - (D - N) - (D - M)) / D, K - (D - N) - (D - M) };
		if (compare(res, tmp)) res = tmp;
	}
	cout << res.second;

	return 0;
}