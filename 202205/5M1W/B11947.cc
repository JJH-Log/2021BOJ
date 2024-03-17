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

lld T, N, t;

lld lovely(lld x) {
	string rev = "";
	lld tmp = x;
	while (tmp) {
		rev += '0' + 9 - (tmp % 10);
		tmp /= 10;
	}
	tmp = 0;
	reverse(rev.begin(), rev.end());
	for (auto c : rev) {
		tmp *= 10;
		tmp += c - '0';
	}
	return x * tmp;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while (T--) {
		cin >> N;
		t = 1;
		while (N >= t) t *= 10;
		t /= 2;
		if (N < t) cout << lovely(N) << '\n';
		else cout << lovely(t) << '\n';
	}

	return 0;
}