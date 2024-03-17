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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int T, N, res, v[10], w[10];

void fillBucket() {
	for (int i = 0; i < N; i++) if (v[i] % 2) v[i]++;
}

void splitCandy() {
	for (int i = 0; i < N; i++) w[i] = 0;
	for (int i = 0; i < N; i++) {
		w[i] += v[i] / 2;
		w[(i + 1) % N] += v[i] / 2;
	}
	for (int i = 0; i < N; i++) v[i] = w[i];
}

bool isSame() {
	int tar = v[0];
	for (int i = 0; i < N; i++) if (tar != v[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		res = 0;
		for (int i = 0; i < N; i++) cin >> v[i];
		fillBucket();
		while (!isSame()) {
			splitCandy();
			fillBucket();
			res++;
		}
		cout << res << '\n';
	}

	return 0;
}
