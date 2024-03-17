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

struct pos {
	int x, y;
};

struct info {
	pos s, e;
	bool clear;
};

lld K;
int N, M;
int v[20][20];
int d[400][400];
pos now;
info man[400];

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }
int en(int x, int y) { return x * 20 + y; }
pos de(int n) { return { n / 20, n % 20 }; }
int getDist(pos a, pos b) { return d[en(a.x, a.y)][en(b.x, b.y)]; }

bool compare(info a, info b) {
	if (a.clear == b.clear) {
		if (getDist(a.s, now) == getDist(b.s, now)) {
			if (a.s.x == b.s.x) return a.s.y < b.s.y;
			return a.s.x < b.s.x;
		}
		return getDist(a.s, now) < getDist(b.s, now);
	}
	return a.clear < b.clear;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}

	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 400; j++) d[i][j] = i == j ? 0 : 1e9;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j]) continue;
			for (int k = 0; k < 4; k++) {
				int dx = i + "2011"[k] - '1';
				int dy = j + "1120"[k] - '1';
				if (inRange(dx, dy) && !v[dx][dy]) {
					d[en(dx, dy)][en(i, j)] = d[en(i, j)][en(dx, dy)] = 1;
				}
			}
		}
	}

	for (int k = 0; k < 400; k++) {
		for (int i = 0; i < 400; i++) {
			for (int j = 0; j < 400; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}

	cin >> now.x >> now.y; now.x--, now.y--;
	for (int i = 0; i < M; i++) {
		cin >> man[i].s.x >> man[i].s.y >> man[i].e.x >> man[i].e.y;
		man[i].s.x--, man[i].s.y--, man[i].e.x--, man[i].e.y--;
	}

	for (int i = 0; i < M; i++){
		sort(man, man + M, compare);
		if (K < getDist(now, man[0].s)) {
			cout << -1;
			return 0;
		}
		K -= getDist(now, man[0].s);
		if (K < getDist(man[0].s, man[0].e)) {
			cout << -1;
			return 0;
		}
		K += getDist(man[0].s, man[0].e);
		man[0].clear = true;
		now = man[0].e;
	}
	cout << K;
	
	return 0;
}