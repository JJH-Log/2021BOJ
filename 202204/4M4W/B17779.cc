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

struct pos {
	int x, y;
};



int N, res, v[20][20];

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }
bool check(int x, int y, int d1, int d2) { return (x + d1 < N) && (y + d2 < N) && (x + d1 + d2 < N) && (y - d1 + d2 < N) && (y - d1 + d2 >= 0) && (x + d1 + d2 < N) && (y + d2 - d1 >= 0) && (y + d2 - d1 < N); }

int solve(int x, int y, int d1, int d2) {
	int mark[20][20] = { 0, };
	int ans[5] = { 0, };
	int i, j, cnt;
	for (j = y, cnt = 0; j >= 0; j--, cnt++) {
		for (int i = 0; i < min(x + cnt, x + d1); i++) mark[i][j] = 1;
	}
	for (i = x + d2, cnt = 0; i >= 0; i--, cnt++) {
		for (int j = N - 1; j > max(y, y + d2 - cnt); j--) mark[i][j] = 2;
	}
	for (i = x + d1, cnt = 0; i < N; i++, cnt++) {
		for (int j = 0; j < min(y - d1 + cnt, y - d1 + d2); j++) mark[i][j] = 3;
	}
	for (j = y - d1 + d2, cnt = 0; j < N; j++, cnt++) {
		for (int i = N - 1; i > max(x + d1 + d2 - cnt, x + d2); i--) mark[i][j] = 4;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) ans[mark[i][j]] += v[i][j];
	}
	sort(ans, ans + 5);
	if (!ans[0]) return 1e9;
	return ans[4] - ans[0];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}

	res = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int d1 = 1; (i + d1 < N) && (j - d1 >= 0); d1++) {
				for (int d2 = 1; check(i, j, d1, d2); d2++) {
					res = min(res, solve(i, j, d1, d2));
				}
			}
		}
	}
	cout << res;
	
	return 0;
}
