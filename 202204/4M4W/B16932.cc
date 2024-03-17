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

int N, M, res;
int v[1000][1000];
int g[1000][1000];
bool vtd[1000][1000];
vector<int> cnt;
int gn;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

int dfs(int x, int y) {
	vtd[x][y] = 1;
	g[x][y] = gn;
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (inRange(dx, dy) && !vtd[dx][dy] && v[dx][dy]) ans += dfs(dx, dy);
	}
	return ans;
}

int test(int x, int y) {
	set<int> s;
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (inRange(dx, dy) && v[dx][dy]) s.insert(g[dx][dy]);
	}
	for (auto t : s) ans += cnt[t];
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}
	cnt.push_back(0); // dummy
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] && !vtd[i][j]) {
				++gn;
				cnt.push_back(dfs(i, j));
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!v[i][j]) res = max(res, test(i, j));
		}
	}
	cout << res + 1;

	return 0;
}
