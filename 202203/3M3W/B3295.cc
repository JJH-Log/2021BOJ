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
#define BOUND 2000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 500005
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, M, p[BOUND], q[BOUND], rn[BOUND];
bool used[BOUND];
vector<int> w[BOUND];

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
		for (int tar : w[now]) {
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

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			w[x].push_back(y);
		}
		int res = 0;
		memset(p, -1, sizeof p);
		memset(q, -1, sizeof q);
		while (true) {
			bfsRank();
			int cnt = 0;
			for (int i = 0; i < N; i++) if (!used[i] && bipartite(i)) cnt++;
			if (!cnt) break;
			res += cnt;
		}
		cout << res << '\n';
		memset(used, false, sizeof used);
		for (int i = 0; i < N; i++) w[i].clear();
	}
	
	return 0;
}