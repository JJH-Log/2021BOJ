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
#include <numeric>
#define MOD 1000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[1020000];
int a, b, d, N;


int _add(int a, int b) { return (a + b) % MOD; }
int _sub(int a, int b) { return (a - b + MOD) % MOD; }
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	cin >> a >> b >> d >> N;
	v[0] = 1; v[1] = -1;

	for (int i = 0; i <= N; i++) {
		if (i) v[i] = _add(v[i - 1], v[i]);
		if (i - a >= 0) v[i] = _add(v[i], v[i - a]);
		if (i - b >= 0) v[i] = _sub(v[i], v[i - b]);
	}
	int res = 0;
	for (int i = 0; i < d && N >= i; i++) res = _add(res, v[N - i]);
	cout << res;
	
	return 0;
}