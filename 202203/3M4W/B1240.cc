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

struct info {
	int par, pard, dep;
};

int N, M;
vector<pii> w[1001];
info v[1001];

void dfs(int now, int parent, int dist, int depth) {
	v[now] = { parent, dist, depth };
	for (auto next : w[now]) {
		if (next.first == parent) continue;
		dfs(next.first, now, next.second, depth + 1);
	}
}

int solve(int x, int y) {
	int ans = 0;
	for (; v[x].dep > v[y].dep; x = v[x].par) ans += v[x].pard;
	for (; v[x].dep < v[y].dep; y = v[y].par) ans += v[y].pard;
	for (; x != y; x = v[x].par, y = v[y].par) ans += v[x].pard + v[y].pard;
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	int x, y, d;
	for (int i = 1; i < N; i++) {
		cin >> x >> y >> d;
		w[x].push_back({ y,d });
		w[y].push_back({ x,d });
	}
	dfs(1, 0, 0, 0);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}

	return 0;
}