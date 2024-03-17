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
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int T, N, Q, v[500], w[500][500], t[500], res[500];
pii res2[500];

int solve() {
	bool FLAG = true;
	queue<int> q;
	fill(t, t + N, 0);

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) t[j] += w[i][j];
		if (!t[j]) q.push(j);
	}
	int cnt = N;
	while (!q.empty()) {
		if (q.size() > 1) FLAG = false;
		int now = q.front(); q.pop();
		res[now] = cnt--;
		for (int j = 0; j < N; j++) {
			if (w[now][j]) {
				t[j]--;
				if (!t[j]) q.push(j);
			}
		}
	}
	if (cnt == 0) {
		if (FLAG) return 0;
		else return 1;
	}
	else return -1;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = N; i > 0; i--) {
			int x;
			cin >> x; x--;
			v[x] = i;
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (v[i] > v[j]) w[i][j] = 1, w[j][i] = 0;
				else w[j][i] = 1, w[i][j] = 0;
			}
		}
		cin >> Q;
		for (int i = 0; i < Q; i++) {
			int x, y;
			cin >> x >> y; x--, y--;
			if (w[x][y]) w[y][x] = 1, w[x][y] = 0;
			else w[x][y] = 1, w[y][x] = 0;
		}
		int ans = solve();
		if (ans == -1) cout << "IMPOSSIBLE";
		else if (ans == 1) cout << "?";
		else {
			for (int i = 0; i < N; i++) res2[i] = { -res[i], i + 1 };
			sort(res2, res2 + N);
			for (int i = 0; i < N; i++) cout << res2[i].second << ' ';
		}
		cout << '\n';
	}
	

	return 0;
}