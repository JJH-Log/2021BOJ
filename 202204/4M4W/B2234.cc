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

int N, M, gn, val, res;
int v[50][50];
int g[50][50];
bool vtd[50][50];
vector<int> cnt;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

int dfs(int x, int y) {
	vtd[x][y] = true;
	g[x][y] = gn;
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		if (v[x][y] & (1 << i)) continue;
		int dx = x + "1012"[i] - '1';
		int dy = y + "0121"[i] - '1';
		if (inRange(dx, dy) && !vtd[dx][dy]) ans += dfs(dx, dy);
	}
	return ans;
}

int test(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int dx = x + "1012"[i] - '1';
		int dy = y + "0121"[i] - '1';
		if (inRange(dx, dy) && g[x][y] != g[dx][dy]) ans = max(ans, cnt[g[dx][dy]]);
	}
	return cnt[g[x][y]] + ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}
	cnt.push_back(0); //dummy
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vtd[i][j]) {
				++gn;
				cnt.push_back(dfs(i, j));
			}
		}
	}
	for (auto tar : cnt) val = max(tar, val);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) res = max(res, test(i, j));
	}
	cout << cnt.size() - 1 << '\n' << val << '\n' << res;

	return 0;
}
