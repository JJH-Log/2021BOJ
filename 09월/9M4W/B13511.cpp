#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
	pair<lld, int> xi, yi; //cost, cnt
};

vector<vector<pair<int, lld>>> v, w;
vector<int> d;
int N, M;
info db;

void dfs(int now, int parent, lld cost, int depth) {
	int t = 1; 
	int idx = 0;
	pair<int, lld> tar;
	d[now] = depth;
	while (depth >= t) {
		if (!idx) v[now].push_back({ parent, cost });
		else {
			tar = v[now][idx - 1];
			v[now].push_back({ v[tar.first][idx - 1].first , v[tar.first][idx - 1].second + tar.second });
		}
		t *= 2;
		idx++;
	}
	for (auto next : w[now]) {
		if (next.first == parent) continue;
		dfs(next.first, now, next.second, depth + 1);
	}
}

int lca(int X, int Y) {
	if (X == Y) return X;
	if (d[X] < d[Y]) return lca(Y, X);
	if (d[X] != d[Y]) {
		int t = 1, idx = 0;
		while (d[X] - t >= d[Y]) {
			t *= 2;
			idx++;
		}
		db.xi.first += v[X][idx - 1].second;
		db.xi.second += t / 2;
		return lca(v[X][idx - 1].first, Y);
	}
	else {
		int t = 1, idx = 0;
		while (v[X][idx].first != v[Y][idx].first) {
			idx++; t *= 2;
			if (idx == v[X].size()) break;
		}
		if (idx == 0) idx++, t *= 2;
		db.xi.first += v[X][idx - 1].second;
		db.xi.second += t / 2;
		db.yi.first += v[Y][idx - 1].second;
		db.yi.second += t / 2;
		return lca(v[X][idx - 1].first, v[Y][idx - 1].first);
	}
}

int trace(int X, int depth) {
	if (!depth) return X;
	int t = 1, idx = 0;
	while (depth - t >= 0) {
		t *= 2;
		idx++;
	}
	return trace(v[X][idx - 1].first, depth - t / 2);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p, x, y, c;
	cin >> N;
	w.resize(N);
	v.resize(N);
	d.resize(N, 0);
	for (int i = 1; i < N; i++) {
		cin >> x >> y >> c;
		x--, y--;
		w[x].push_back({ y, c });
		w[y].push_back({ x, c });
	}
	dfs(0, -1, -1, 0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		db.xi.first = db.yi.first = db.xi.second = db.yi.second = 0;
		cin >> p >> x >> y;
		x--, y--;
		if (p == 2) cin >> c;
		lca(x, y);
		if(p == 1) cout << db.xi.first + db.yi.first << '\n';
		else {
			if (d[x] < d[y]) swap(db.xi.second, db.yi.second);
			if (c <= db.xi.second) cout << trace(x, c - 1) + 1 << '\n';
			else cout << trace(y, db.xi.second + db.yi.second + 1 - c) + 1 << '\n';
		}
	}

	return 0;
}