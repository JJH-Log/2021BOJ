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

bitset<4004001> bs;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int D1, D2, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> D1 >> D2;
	for (int i = D1; i <= D2; i++) {
		for (int j = 1; j < i; j++) {
			int g = gcd(j, i);
			int tar = (j / g) * 2001 + (i / g);
			if (!bs[tar]) {
				res++;
				bs[tar] = 1;
			}
		}
	}
	cout << res + 1;

	return 0;
}