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

vector<pii> w[5001];
int N, Q, g[5001];

int dfs(int now, int parent, int K) {
	int ans = 1;
	for (auto tar : w[now]) {
		if (tar.first == parent) continue;
		if (tar.second >= K) ans += dfs(tar.first, now, K);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> Q;
	int x, y, r;
	for (int i = 1; i < N; i++) {
		cin >> x >> y >> r;
		w[x].push_back({ y, r });
		w[y].push_back({ x, r });
	}
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		cout << dfs(y, -1, x) - 1 << '\n';
	}
	
	return 0;
}