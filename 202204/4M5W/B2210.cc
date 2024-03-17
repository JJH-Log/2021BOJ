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
#define MOD 86400
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


bitset<1000000> bs;
int v[5][5], res;

void dfs(int x, int y, int cnt, int now) {
	if (cnt == 6) {
		if (!bs[now]) {
			bs[now] = 1;
			res++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (dx < 0 || dx > 4 || dy < 0 || dy > 4) continue;
		dfs(dx, dy, cnt + 1, now * 10 + v[x][y]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) cin >> v[i][j];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) dfs(i, j, 0, 0);
	}
	cout << res;

	return 0;
}
