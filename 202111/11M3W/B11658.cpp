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
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

//Code referenced by jaehoon0124
lld N, M, v[1025][1025], tree[1025][1025];

void update(int x, int y, int val) {
	for (int i = x; i <= N; i += i & -i) {
		for (int j = y; j <= N; j += j & -j) {
			tree[i][j] += val;
		}
	}
}

lld sum(int x, int y) {
	lld ans = 0;
	for (int i = x; i > 0; i -= i & -i) {
		for (int j = y; j > 0; j -= j & -j) {
			ans += tree[i][j];
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
			update(i, j, v[i][j]);
		}
	}
	for (int i = 0; i < M; i++) {
		int w, a, b, c, d;
		lld ans;
		cin >> w;
		if (!w) {
			cin >> a >> b >> c;
			update(a, b, c - v[a][b]);
			v[a][b] = c;
		}
		else {
			cin >> a >> b >> c >> d;
			ans = sum(c, d) - sum(c, b - 1) - sum(a - 1, d) + sum(a - 1, b - 1);
			cout << ans << '\n';
		}

	}

	return 0;
}
