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

int N, res, v[102][102], w[102][102];

int sol(int x1, int y1, int x2, int lo, int hi) {
	if (lo > hi) return -1;
	int mid = (lo + hi) / 2;
	int val = w[x2][mid] - w[x2][y1 - 1] - w[x1 - 1][mid] + w[x1 - 1][y1 - 1];
	if (val == (x2 - x1 + 1) * (mid - y1 + 1)) {
		int ans = max(mid, sol(x1, y1, x2, mid + 1, hi));
		return ans;
	}
	else return sol(x1, y1, x2, lo, mid - 1);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		for (int dx = 1; dx <= 10; dx++) for (int dy = 1; dy <= 10; dy++) v[x + dx][y + dy] = 1;
	}
	for (int i = 1; i <= 101; i++) for (int j = 1; j <= 101; j++) w[i][j] = v[i][j] + w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
	
	for (int x1 = 1; x1 <= 101; x1++) {
		for (int y1 = 1; y1 <= 101; y1++) {
			//setting i, j to pivot
			if (!v[x1][y1]) continue;
			for (int dx = 0; x1 + dx <= 101; dx++) {
				int y2 = sol(x1, y1, x1 + dx, y1, 101);
				res = max(res, (dx + 1) * (y2 - y1 + 1));
			}
		}
	}
	cout << res;

	return 0;
}
