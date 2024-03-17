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

lld M, N;
lld v[1000000];
lld ans, mid, res, lo, hi, total;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		total += v[i];
	}
	if (total < M) {
		cout << 0;
		return 0;
	}

	lo = 0, hi = 1e9;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		ans = 0;
		for (int i = 0; i < N; i++) ans += v[i] / mid;
		if (ans < M) hi = mid - 1;
		else {
			res = mid;
			lo = mid + 1;
		}
	}
	cout << res;

	return 0;
}