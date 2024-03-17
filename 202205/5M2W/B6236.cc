#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, K;
lld v[100000];
lld vMax, total;

int simulation(lld k) {
	int cnt = 1;
	lld now = k;
	for (int i = 0; i < N; i++) {
		if (now >= v[i]) now -= v[i];
		else {
			now = k;
			cnt++;
			now -= v[i];
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		vMax = max(vMax, v[i]);
		total += v[i];
	}

	lld lo, hi, mid, ans, res;
	lo = vMax, hi = total;

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		int tar = simulation(mid);
		if (tar > M) lo = mid + 1;
		else {
			res = hi;
			hi = mid - 1;
		}
	}
	cout << res;

	return 0;
}