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
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

//Code referenced by kks227
int N, p[BOUND], q[BOUND], rn[BOUND];
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (scanf("%d", &N) > 0) {
		for (int i = 0; i < N; i++) {
			int M, J;
			scanf("%d: (%d)", &M, &J);
			for (int j = 0; j < J; j++) {
				int x;
				scanf("%d", &x);
				w[M].push_back(x - N);
			}
		}
		int result = 0;
		fill(p, p + BOUND, -1);
		fill(q, q + BOUND, -1);
		while (true) {
			bfsRank();
			int cnt = 0;
			for (int i = 0; i < N; i++) if (!used[i] && bipartite(i)) cnt++;
			if (!cnt) break;
			result += cnt;
		}
		printf("%d\n", result);

		fill(used, used + BOUND, false);
		for (int i = 0; i < N; i++) w[i].clear();
	}
	return 0;
}
