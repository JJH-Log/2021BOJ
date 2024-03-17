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

lld N, X, K;

int bitNum(lld x) {
	int ans = 0;
	while (x) {
		ans += (x % 2);
		x /= 2;
	}
	return ans;
}

lld newBit(lld n, lld tar) {
	lld ans = 0;
	lld t = 0;
	for (int t = 31; t >= 0; t--) {
		if (t > tar) ans += (n & ((lld)1 << t));
		if (t == tar) ans += ((lld)1 << t);
	}
	if (ans == 0) return ((lld)1 << tar);
	return ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	if (bitNum(N) <= K) {
		cout << 0;
		return 0;
	}
	for (int t = 0; t < 63; t++) {
		if (((lld)1 << t) & N) continue;
		X = newBit(N, t);
		if (bitNum(X) <= K) {
			cout << X - N;
			return 0;
		}
	}

	return 0;
}