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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct road {
	int x, idx;
};

bool vtdE[200101];
bool vtd[100101];
int ptr[100101];
int ans[200101];
vector<road> w[100101];
int N, E, S, C, dn, color;
bool FLAG;

void dfs(int now) {
	if (now == 0) return;
	vtd[now] = true; C++;
	for (road tar : w[now]) {
		if (vtd[tar.x]) continue;
		dfs(tar.x);
	}
	if (w[now].size() != 2) S = now;
	if (w[now].size() % 2) {
		w[now].push_back({ 0, dn });
		w[0].push_back({ now, dn++ });
	}
	ptr[now] = w[now].size() - 1;
}

void dfs2(int now, int edge) {
	while (w[now].size()) {
		road tar = w[now].back();
		w[now].pop_back();
		if (!vtdE[tar.idx]) {
			vtdE[tar.idx] = true;
			dfs2(tar.x, tar.idx);
		}
	}
	if (edge != -1) ans[edge] = color;
	color = (color ^ 3);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;
	for (int i = 1; i <= E; i++) {
		int x, y;
		cin >> x >> y;
		w[x].push_back({ y, i });
		w[y].push_back({ x, i });
	}
	FLAG = false; dn = E + 1;
	for (int i = 1; i <= N; i++) {
		if (!vtd[i]) {
			w[0].clear();
			S = C = 0;
			dfs(i);
			ptr[0] = w[0].size() - 1; color = 1;
			if ((!S) && (C % 2)) {
				cout << "0\n";
				return 0;
			}
			else {
				if (!S) S = i;
				dfs2(S, -1);
			}
		}
	}
	for (int i = 1; i <= E; i++) cout << ans[i] << '\n';

	return 0;
}
