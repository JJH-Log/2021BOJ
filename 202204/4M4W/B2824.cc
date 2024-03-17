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

int N, M, G, A[1000], B[1000];
lld res = 1;

bool FLAG;

int gcd(int X, int Y) {
	if (Y == 0) return X;
	return gcd(Y, X % Y);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> B[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			G = gcd(A[i], B[j]);
			A[i] /= G;
			B[j] /= G;
			res = res * (lld)G;
			if (res >= 1e9) FLAG = true;
			res = res % BOUND;
		}
	}
	if (FLAG) {
		string r = to_string(res);
		for (int i = 0; i < 9 - r.size(); i++) cout << '0';
		cout << r;
	}
	else cout << res;

	return 0;
}
