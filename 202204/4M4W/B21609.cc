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

struct pos {
	int x, y;
};

struct group {
	pos p;
	int sz, rb;
};

int N, M, v[20][20], res;
bool vtd[20][20];
vector<group> G;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }

bool cmp_group(group a, group b) {
	if (a.sz == b.sz) {
		if (a.rb == b.rb) {
			if (a.p.x == b.p.x) return a.p.y > b.p.y;
			return a.p.x > b.p.x;
		}
		return a.rb > b.rb;
	}
	return a.sz > b.sz;
}

void bfs(pos p, bool FLAG) {
	bool used[20][20] = { 0, };
	queue<pos> q;
	vtd[p.x][p.y] = true;
	used[p.x][p.y] = true;
	group ans = { p, 1, 0 };
	q.push(p);

	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy)) {
				if (v[dx][dy] == 0 && !used[dx][dy]) {
					used[dx][dy] = true;
					ans.sz++; ans.rb++;
					q.push({ dx, dy });
					if (FLAG) v[dx][dy] = -9;
				}
				if (v[dx][dy] == v[p.x][p.y] && !used[dx][dy]) {
					vtd[dx][dy] = used[dx][dy] = true;
					ans.sz++;
					q.push({ dx, dy });
					if (FLAG) v[dx][dy] = -9;
				}
			}
		}
	}
	if (FLAG) v[p.x][p.y] = -9;
	else if (ans.sz > 1) G.push_back(ans);
}

bool find_group() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) vtd[i][j] = false;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] > 0 && !vtd[i][j]) bfs({ i, j }, false);
		}
	}
	if (!G.size()) return false;
	sort(G.begin(), G.end(), cmp_group);
	res += G[0].sz * G[0].sz;
	bfs(G[0].p, true);
	G.clear();
	return true;
}

void gravity() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] < 0) continue;
			pos now = { i, j };
			while (true) {
				pos next = { now.x + 1, now.y };
				if (!inRange(next.x, next.y) || v[next.x][next.y] != -9) break;
				swap(v[now.x][now.y], v[next.x][next.y]);
				now = next;
			}
		}
	}
}

void turn_ccw() {
	int w[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) w[N - 1 - j][i] = v[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) v[i][j] = w[i][j];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	while (true) {
		if (!find_group()) break;
		gravity();
		turn_ccw();
		gravity();
	}
	cout << res;

	return 0;
}
