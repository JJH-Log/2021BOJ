#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[5000], ans[5000];
int N, p[5000], q[5000], rn[5000];
bool used[5000];
vector<int> w[5000];

void bfsRank() {
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			rn[i] = 0;
			Q.push(i);
		}
		else rn[i] = 1e9;
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (auto tar : w[now]) {
			if (q[tar] != -1 && rn[q[tar]] == 1e9) {
				rn[q[tar]] = rn[now] + 1;
				Q.push(q[tar]);
			}
		}
	}
}

bool bipartite(int now) {
	for (int tar : w[now]) {
		if (q[tar] == -1 || (rn[q[tar]] == rn[now] + 1 && bipartite(q[tar]))) {
			used[now] = true;
			p[now] = tar;
			q[tar] = now;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[i] != v[j]) {
				w[i].push_back(j);
				w[j].push_back(i);
			}
		}
	}
	int res = 0;
	fill(p, p + N, -1);
	fill(q, q + N, -1);
	while (true) {
		bfsRank();
		int cnt = 0;
		for (int i = 0; i < N; i++) if (!used[i] && bipartite(i)) cnt++;
		if (!cnt) break;
		res += cnt;
	}
	if (res != N) cout << -1;
	else {
		for (int i = 0; i < N; i++) ans[p[i]] = v[i];
		for (int i = 0; i < N; i++) cout << ans[i] << ' ';
	}
	return 0;
}