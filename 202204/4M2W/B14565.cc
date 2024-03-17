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

//Reference : https://rebro.kr/97
lld N, X, C, K;

lld EEA(lld A, lld B, lld& s, lld& t) {
	if (B == 0) {
		s = 1, t = 0;
		return A;
	}
	lld gcd = EEA(B, A % B, s, t);
	lld tmp = t;
	t = s - (A / B) * t;
	s = tmp;
	if (s <= 0) {
		s += B;
		t -= A;
	}
	return gcd;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> X;
	lld ans = EEA(X, N, C, K);
	if (ans != 1) cout << N - X << ' ' << -1;
	else cout << N - X << ' ' << C;

	return 0;
}