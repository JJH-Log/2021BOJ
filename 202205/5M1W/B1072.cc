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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld X, Y, Z;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> X >> Y;
	if (X == Y) {
		cout << -1;
		return 0;
	}
	Z = 100 * Y / X;
	if (Z == 99) {
		cout << -1;
		return 0;
	}
	Z++;
	lld P = (Z * X - 100 * Y) / (100 - Z);
	if ((Z * X - 100 * Y) % (100 - Z) == 0) cout << P;
	else cout << P + 1;

	return 0;
}