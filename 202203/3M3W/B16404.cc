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

struct area {
	int s, e;
};

lld tree[100002];
area v[100000];
vector<int> w[100000];
int N, M, dfsn;

int dfs(int now, int parent) {
	v[now].s = ++dfsn;
	int FLAG = v[now].s;
	for (auto next : w[now]) {
		if (next == parent) continue;
		FLAG = max(FLAG, dfs(next, now));
	}
	return v[now].e = FLAG;
}

void update(int X, int key) {
	for (int i = X; i <= N; i += i & -i) tree[i] += (lld)key;
}

lld query(int X) {
	lld ans = 0;
	for (int i = X; i; i -= i & -i) ans += tree[i];
	return ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x; x--;
		if (x >= 0) {
			w[i].push_back(x);
			w[x].push_back(i);
		}
	}
	dfs(0, -1);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		area now;
		cin >> a >> b; now = v[b - 1];
		if (a == 1) {
			cin >> c;
			update(now.s, c);
			update(now.e + 1, -c);
		}
		else cout << query(now.s) << '\n';
	}

	return 0;
}