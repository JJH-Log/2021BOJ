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
#define BOUND 1000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 500005
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> w[MAXN];
lld ftr[MAXN];
lld rm;
int d[MAXN];
int sz[MAXN];
int par[MAXN];
int N, maxd;
int T = 0;
lld res;
int label[MAXN];

vector<int> dlist[MAXN];

void addEdge(int x, int y) {
	w[x].push_back(y);
	w[y].push_back(x);
}

lld getRm(int x, int y) {
	if (x > y) return getRm(y, x);
	return (MAXN * (lld)x + y);
}

int getSize(int now, int parent) {
	sz[now] = 1;
	for (auto next : w[now]) if (next != parent) sz[now] += getSize(next, now);
	return sz[now];
}

int getCentroid(int now, int parent, int cap) {
	for (auto next : w[now]) if (next != parent && sz[next] > cap) return getCentroid(next, now, cap);
	return now;
}

int checkDoubleCenter(int now, int cap) {
	for (auto next : w[now]) {
		if (sz[next] == cap) {
			addEdge(now, T);
			addEdge(next, T);
			rm = getRm(now, next);
			return T;
		}
	}
	return now;
}

void dfs(int now, int parent, int depth) {
	d[now] = depth; dlist[depth].push_back(now); par[now] = parent;
	for (auto next : w[now]) if (next != parent && rm != getRm(now, next)) dfs(next, now, depth + 1);
	maxd = max(maxd, depth);
}

void solve() {
	for (int lv = maxd; lv >= 0; lv--) {
		vector<pair<vector<int>, int>> v;
		for (auto now : dlist[lv]) {
			vector<int> tmp;
			for (auto child : w[now]) {
				if (child == par[now]) continue;
				tmp.push_back(label[child]);
			}
			sort(tmp.begin(), tmp.end());
			int cnt = 0;
			for (int i = 0; i < tmp.size(); i++) {
				if (i != 0 && tmp[i] != tmp[i - 1]) res = (res * ftr[cnt]) % MOD, cnt = 1;
				else cnt++;
			}
			if(cnt > 1) res = (res * ftr[cnt]) % MOD;
			v.push_back({ tmp, now });
		}
		sort(v.begin(), v.end());

		int pv = 0;
		for (int i = 0; i < v.size(); i++) {
			if (i != 0 && v[i].first == v[i - 1].first) label[v[i].second] = pv;
			else label[v[i].second] = ++pv;
		}
		v.clear();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ftr[1] = 1;
	for (int i = 2; i <= 500000; i++) ftr[i] = (ftr[i - 1] * i) % MOD;

	cin >> N;
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y; 
		addEdge(x, y);
	}
	getSize(1, -1);
	int center = getCentroid(1, -1, N / 2);
	if (N % 2 == 0) center = checkDoubleCenter(center, N / 2);
	dfs(center, -1, 0);
	res = 1;
	
	solve();
	cout << res;
	return 0;
}