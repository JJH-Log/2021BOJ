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

int N, M;
int v[500][500];
bool vtd[500][500];

bool inRange(int x, int y) {
	return (x >= 0) && (x < N) && (y >= 0) && (y < M);
}

int dfs(int x, int y) {
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (inRange(dx, dy) && v[dx][dy] && !vtd[dx][dy]) {
			vtd[dx][dy] = 1;
			ans += dfs(dx, dy);
		}
	}
	return ans;
}
int cnt, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vtd[i][j] && v[i][j]) {
				cnt++;
				vtd[i][j] = 1;
				res = max(res, dfs(i, j));
			}
		}
	}
	cout << cnt << '\n' << res;
	
	

	return 0;
}