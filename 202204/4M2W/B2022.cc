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

double A, B, C;
double solve(double lo, double hi) {
	if (lo > hi) return lo;
	double mid = (lo + hi) / 2;
	double ak = sqrt(A * A - mid * mid);
	double bk = sqrt(B * B - mid * mid);
	double c = ak * bk / (ak + bk);

	if (c >= C) return solve(mid + 0.00001, hi);
	else return solve(lo, mid - 0.00001);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(3);
	cout << fixed;

	cin >> A >> B >> C;
	cout << solve(0, min(A, B));

	return 0;
}