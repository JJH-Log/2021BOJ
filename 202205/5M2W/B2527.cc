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

struct square {
	int x, y, p, q;
	bool isOutRange(square tar) { return (q < tar.y || tar.q < y || p < tar.x || tar.p < x); }
	int isOnLine(square tar) {
		if (p == tar.x || x == tar.p) return (q == tar.y || y == tar.q);
		if (q == tar.y || y == tar.q) return (x == tar.p || p == tar.x);
		return -1;
	}
};

square A, B;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		cin >> A.x >> A.y >> A.p >> A.q >> B.x >> B.y >> B.p >> B.q;
		if (A.isOutRange(B)) cout << "d\n";
		else if (A.isOnLine(B) == -1) cout << "a\n";
		else cout << (char)('b' + A.isOnLine(B)) << '\n';
	}

	return 0;
}