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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
int v[101][101];
int gn, u[101];
int g[101];
int total[101];
int res[101];

int find(int X) {
	if (u[X] == X) return X;
	return u[X] = find(u[X]);
}

void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (x > y) swap(x, y);
	u[y] = x;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) if(i != j) v[i][j] = 1e9;
	}
	iota(u + 1, u + N + 1, 1);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x][y] = v[y][x] = 1;
		merge(x, y);
	}
	for (int i = 1; i <= N; i++) {
		if (u[i] == i) g[i] = ++gn, res[g[i]] = i;
		else g[i] = g[find(i)];
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) if (v[i][j] != 1e9) total[i] = max(total[i], v[i][j]);
		if (total[i] < total[res[g[i]]]) res[g[i]] = i;
	}

	cout << gn << '\n';
	sort(res + 1, res + gn + 1);
	for (int i = 1; i <= gn; i++) cout << res[i] << '\n';

	return 0;
}