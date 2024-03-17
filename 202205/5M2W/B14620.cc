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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, v[10][10], res;
bool check[10][10];
int w[3];

void backTracking(int idx, int cnt) {
	if (cnt == 3) {
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			int x = w[i] / N;
			int y = w[i] % N;
			for (int j = 0; j < 5; j++) {
				int dx = x + "20111"[j] - '1';
				int dy = y + "11201"[j] - '1';
				ans += v[dx][dy];
			}
		}
		res = min(res, ans);
		return;
	}

	for (int i = idx; i < N * N; i++) {
		int x = i / N;
		int y = i % N;
		if (x == 0 || x == N - 1 || y == 0 || y == N - 1) continue;
		if (check[x - 1][y] || check[x][y - 1] || check[x - 1][y - 1] || check[x - 1][y + 1]) continue;
		if (x > 1 && check[x - 2][y]) continue;
		if (y > 1 && check[x][y - 2]) continue;
		check[x][y] = true;
		w[cnt] = i;
		backTracking(i + 1, cnt + 1);
		check[x][y] = false;
	}
}



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	res = 1e9;
	backTracking(0, 0);
	cout << res;

	return 0;
}