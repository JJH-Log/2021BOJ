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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, K;

lld combination(lld n, lld k) {
	if ((n + 1) / 2 < k) return combination(n, n - k);
	lld ans, tmp;
	ans = tmp = 1;
	for (lld i = 0; i < k; i++) {
		ans *= (n - i);
		while (tmp <= k && (ans % tmp) == 0) {
			ans /= tmp;
			tmp++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> N >> K;
		if (N == 0 && K == 0) break;
		cout << combination(N, K) << '\n';
	}

	return 0;
}