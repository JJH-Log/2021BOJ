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

struct info {
	lld S, W;
};

int N, a, p;
char t;
info v[123456];
vector<int> w[123456];

lld dfs(int now, int parent) {
	for (auto tar : w[now]) {
		if (tar == parent) continue;
		v[now].S += dfs(tar, now);
	}
	return max(v[now].S - v[now].W, (lld)0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> t >> a >> p; p--;
		if (t == 'S') v[i].S = a;
		else v[i].W = a;
		w[p].push_back(i);
		w[i].push_back(p);
	}
	cout << dfs(0, -1);

	return 0;
}