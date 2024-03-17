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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

/*
X개의 방 중 첫번째 방이 배정될 확률 (p[X]) : 1/(X - 1) * [1(i = 0) + 0(i = 1) + p[2](i = 2) + p[3](i = 3).... p[X - 2](i = X - 1)]
 → Using prefix Sum
X개의 방 중 K번째 방이 배정될 확률
 (1) 호텔을 (1, K), (K, N)으로 분리
 (2) (1, K) 에서 K번째 방이 배정되지 않을 확률 = (1 - p[K]) *양끝의 확률은 같으므로
 (3) (K, N) 에서 K번째 방이 배정되지 않을 확률 = (1 - p[N - K + 1])
 (4) 따라서, res(X, K) = 1 - (1 - p[K]) * (1 - p[N - K + 1])
*/

lld p[10000001];
lld psum[3];
lld N, K;

lld mul(lld a, lld b) { return (a * b) % MOD; }
lld add(lld a, lld b) { return (a + b) % MOD; }
lld invp(lld p) { return (MOD + 1 - p) % MOD; }

lld inv(lld X) {
	lld res = 1;
	lld p = MOD - 2;
	while (p) {
		if (p % 2) res = (res * X) % MOD;
		X = mul(X, X);
		p /= 2;
	}
	return res;
}
lld res(lld n, lld k) { return invp(mul(invp(p[k]), invp(p[n - k + 1]))); }


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	p[0] = 1, p[1] = 0; psum[0] = psum[1] = 1;
	for (int i = 2; i <= 10000000; i++) {
		p[i] = mul(psum[(i - 2) % 3], inv((lld)i - 1));
		psum[i % 3] = add(psum[(i - 1) % 3], p[i]);
	}
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		cout << "Case #" << i << ": " << res(N, K) << '\n';
	}

	return 0;
}
