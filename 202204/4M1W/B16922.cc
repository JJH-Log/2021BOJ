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
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, res, v[4];
int d[4] = { 1, 5, 10, 50 };
bitset<1001> bs;

void solve(int cnt, int left) {
	if (cnt == 3) {
		int ans = 0;
		v[cnt] = left;
		for (int i = 0; i < 4; i++) ans += v[i] * d[i];
		if (!bs[ans]) {
			bs[ans] = 1;
			res++;
		}
		return;
	}
	for (int i = 0; i <= left; i++) {
		v[cnt] = i;
		solve(cnt + 1, left - i);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solve(0, N);
	cout << res;

	return 0;
}