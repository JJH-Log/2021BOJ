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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, M, K;
lld v[10];
lld res;

void simulation(lld t, lld now, lld stock, lld borrow) {
	if (t == N) {
		if (stock == 0) res = max(res, now);
		return;
	}
	if(stock) simulation(t + 1, now, stock, borrow);
	now = now + v[t] * stock;
	simulation(t + 1, now, 0, borrow);
	if (borrow) {
		now -= borrow;
		borrow = 0;
	}
	if (now * (K + 1) >= v[t]) {
		borrow = now * K;
		now += borrow;
		simulation(t + 1, now % v[t], now / v[t], borrow);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	simulation(0, M, 0, 0);
	cout << res;
	return 0;
}