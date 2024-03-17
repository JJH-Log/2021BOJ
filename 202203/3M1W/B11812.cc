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
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, K, Q, X, Y;

lld getParent(lld tar) {
	if (tar % K == 0 || tar % K == 1) return (tar / K);
	else return (tar / K) + 1;
}

int solve(lld x, lld y) {
	int cnt = 0;
	while (x != y) {
		if (x < y) y = getParent(y);
		else x = getParent(x);
		cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> Q;
	for (int i = 0; i < Q; i++) {
		lld x, y;
		cin >> x >> y;
		if (K == 1) cout << abs(x - y) << '\n';
		else  cout << solve(x, y) << '\n';
	}
	return 0;
}
