#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<lld> v;
int N, L, R;
lld result;

lld gcd(lld X, lld Y) {
	if (Y == 0) return X;
	if (X < Y) return gcd(Y, X);
	return gcd(Y, X % Y);
}

lld lcm(lld X, lld Y) {
	lld now = (lld)X * Y / gcd(X, Y);
	if (now > 1000000000) return 0;
	return now;
}

void solve(lld now, int idx, int cnt) {
	if (!now) return;
	for (int i = idx; i < N; i++) {
		solve(lcm(now, v[i]), i + 1, cnt + 1);
	}
	if (!cnt) return;
	if (cnt % 2) result += (R / now) - ((L - 1) / now);
	else result -= (R / now) - ((L - 1) / now);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> L >> R;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	result = 0;
	solve(1, 0, 0);
	cout << result;

	return 0;
}