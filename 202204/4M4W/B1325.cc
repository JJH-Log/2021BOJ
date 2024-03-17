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

int N, M;
vector<int> w[10001];
stack<int> st;
vector<vector<int>> g;
int gn[10001];
int dn[10001];
int dfsn, grn;

set<int> gw[10001];
bool gvtd[10001], ff[10001];
int res;
vector<int> r;

int scc(int now) {
	dn[now] = ++dfsn;
	st.push(now);
	int FLAG = dn[now];
	for (auto tar : w[now]) {
		if (gn[tar]) continue;
		if (dn[tar]) FLAG = min(FLAG, dn[tar]);
		else FLAG = min(FLAG, scc(tar));
	}
	if (FLAG == dn[now]) {
		vector<int> tmp;
		++grn;
		int t;
		while (true) {
			t = st.top(); st.pop();
			tmp.push_back(t);
			gn[t] = grn;
			if (t == now) break;
		}
		g.push_back(tmp);
	}
	return FLAG;
}

int dfs(int now) {
	gvtd[now] = true;
	int ans = g[now].size();
	for (auto mem : g[now]) {
		for (auto tar : w[mem]) {
			if(now != gn[tar] && !gvtd[gn[tar]]) ans += dfs(gn[tar]);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		w[b].push_back(a);
	}
	g.push_back(vector<int>(0));
	for (int i = 1; i <= N; i++) if (!dn[i]) scc(i);


	for (int i = 1; i <= grn; i++) {
		fill(gvtd + 1, gvtd + N + 1, false);
		int ans = dfs(i);
		if (ans > res) {
			r.clear();
			res = ans;
			r.push_back(i);
		}
		else if (ans == res) r.push_back(i);
	}
	for (auto tar : r) {
		for (auto mem : g[tar]) ff[mem] = true;
	}
	for (int i = 1; i <= N; i++)if (ff[i]) cout << i << ' ';

	return 0;
}
