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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct info {
	int ni, no, nd;
};


int N, C, Q, dfsn;
int tree[200002];
info v[200002];
vector<vector<int>> w;

void dfs(int now, int parent, int depth) {
	v[now].nd = depth;
	v[now].ni = ++dfsn;
	for (auto next : w[now]) {
		if (next == parent) continue;
		dfs(next, now, depth + 1);
	}
	v[now].no = dfsn;
}

void update(int x, int val) {
	for (int i = x; i <= N; i += i & -i) tree[i] += val;
}

int total(int x) {
	int ans = 0;
	for (int i = x; i > 0; i -= i & -i) ans += tree[i];
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> N >> C;
	w.resize(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dfsn = 0;
	dfs(C, -1, 1);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		if (x == 1) update(v[y].ni, 1);
		if (x == 2) {
			cout << ((lld)total(v[y].no) - total(v[y].ni - 1)) * v[y].nd << '\n';
		}
	}

	
	return 0;
}
