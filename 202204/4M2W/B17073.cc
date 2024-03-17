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

int N, W, res;
vector<int> w[500000];

void dfs(int now, int parent) {
	int cnt = 0;
	for (auto next : w[now]) {
		if (next == parent) continue;
		cnt++; dfs(next, now);
	}
	if (!cnt) res++;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(5);

	cin >> N >> W;
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y; x--, y--;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dfs(0, -1);
	cout << ((double)W / res);

	return 0;
}