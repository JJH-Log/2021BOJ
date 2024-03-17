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
#define MAXS 500000
using namespace std;
using lld = long long;
using pii = pair<int, int>;


vector<lld> v;
vector<lld> num;

void init(int vSize) {
	v.resize(vSize + 1, 0);
	v[0] = 1;
	for (int i = 1; i <= vSize; i++) v[i] = (v[i - 1] * i) % MOD;
}

lld sqrPow(lld X, lld P) { //X^P
	lld result = 1;
	while (P) {
		if (P % 2 == 1) result = (result * X) % MOD;
		X = (X * X) % MOD;
		P /= 2;
	}
	return result;
}

lld combination(lld N, lld K) {
	//cout << "N, K : " << N << ' ' << K << endl;
	if (N < K || N < 0 || K < 0) return 0;
	return (v[N] * sqrPow((v[N - K] * v[K]) % MOD, MOD - 2)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//result = sCv2 * Sum[for (k = 0 : S - v2[=lo]) { loCk* v2C(v1 - k)* (v2 + k)C(v0 - (lo - k)) }]
	num.resize(3, 0);
	lld k, S, left_over;
	lld result, result2, temp;
	cin >> S >> num[0] >> num[1] >> num[2];
	if (num[0] + num[1] + num[2] < S) {
		cout << 0;
		return 0;
	}
	init(1000000);
	sort(num.begin(), num.end());
	result = combination(S, num[2]);
	result2 = 0;
	left_over = S - num[2];
	for (k = 0; k <= left_over; k++) {
		temp = combination(left_over, k);
		temp = (temp * combination(num[2], num[1] - k)) % MOD;
		temp = (temp * combination(num[2] + k, num[0] - (left_over - k))) % MOD;
		result2 += temp;
	}
	cout << (result * (result2 % MOD)) % MOD;

	return 0;
}
