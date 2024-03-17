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
string v[500];
int vtd[500][500];
string tar = "URDL";

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

int dfs(int x, int y) {
	if (vtd[x][y]) return vtd[x][y];
	int d = tar.find(v[x][y]);
	int dx = x + "0121"[d] - '1';
	int dy = y + "1210"[d] - '1';
	if (!inRange(dx, dy)) return vtd[x][y] = -1;
	vtd[x][y] = 1;
	return vtd[x][y] = dfs(dx, dy);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vtd[i][j]) dfs(i, j);
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) res += (vtd[i][j] == -1);
	}
	cout << res;

	return 0;
}