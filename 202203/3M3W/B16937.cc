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

struct info {
	int h, w, a;
};

info v[100];
int H, W, N, res;

bool isAble(info A, info B) {
	if (max(A.h, B.h) <= H && A.w + B.w <= W) return true;
	if (max(A.h, B.w) <= H && A.w + B.h <= W) return true;
	if (max(A.w, B.h) <= H && A.h + B.w <= W) return true;
	if (max(A.w, B.w) <= H && A.h + B.h <= W) return true;
	if (A.h + B.h <= H && max(A.w, B.w) <= W) return true;
	if (A.h + B.w <= H && max(A.w, B.h) <= W) return true;
	if (A.w + B.h <= H && max(A.h, B.w) <= W) return true;
	if (A.w + B.w <= H && max(A.h, B.h) <= W) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i].h >> v[i].w;
		v[i].a = v[i].h * v[i].w;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (isAble(v[i], v[j])) res = max(res, v[i].a + v[j].a);
		}
	}
	cout << res;

	return 0;
}