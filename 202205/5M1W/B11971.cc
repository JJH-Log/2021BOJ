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

int N, M, x, y, bx, t, res;
int v[100], w[100];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		t += x;
		for (int i = bx; i < t; i++) v[i] = y;
		bx = t;
	}

	t = bx = 0;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		t += x;
		for (int i = bx; i < t; i++) w[i] = y;
		bx = t;
	}

	for (int i = 0; i < 100; i++) res = max(res, w[i] - v[i]);
	cout << res;

	return 0;
}
