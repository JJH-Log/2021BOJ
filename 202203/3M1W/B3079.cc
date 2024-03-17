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
using ld = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, M;
lld T[100000];
lld res;

void solve(lld lo, lld hi) {
	if (lo > hi) return;
	lld mid = (lo + hi) / 2;
	lld ans = 0;
	for (int i = 0; i < N; i++) ans += mid / T[i];
	if (ans >= M) {
		res = mid;
		solve(lo, mid - 1);
	}
	else solve(mid + 1, hi);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	res = (lld)1e19;
	assert(T[N - 1] * M <= 1e18);
	solve(1, T[N - 1] * M);
	cout << res;

	return 0;
}
