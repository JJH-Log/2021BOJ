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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct line {
	int x1, x2, y1, y2, w;
};

vector<line> v1, v2;
int N, M, S, E;
vector<int> w[402];
int c[402][402], f[402][402], d[402][402];
bool inQ[402];
int par[402], dst[402];

void doFlow() {
	queue<int> q;
	dst[S] = 0;
	inQ[S] = true;
	q.push(S);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		inQ[now] = false;
		for (auto next : w[now]) {
			if (c[now][next] - f[now][next] > 0 && dst[next] > dst[now] + d[now][next]) {
				par[next] = now;
				dst[next] = dst[now] + d[now][next];
				if (!inQ[next]) {
					inQ[next] = true;
					q.push(next);
				}
			}
		}
	}
}

pii networkFlow() {
	pii result = { 0, 0 };
	while (true) {
		fill(dst, dst + 402, 1e9);
		fill(par, par + 402, -1);
		fill(inQ, inQ + 402, false);
		doFlow();
		if (par[E] == -1) break;

		int flow = (int)1e9;
		for (int now = E; now != S; now = par[now]) flow = min(flow, c[par[now]][now] - f[par[now]][now]);
		for (int now = E; now != S; now = par[now]) {
			result.second += flow * d[par[now]][now];
			f[par[now]][now] += flow;
			f[now][par[now]] -= flow;
		}
		result.first++;
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		v1.resize(N + 1);
		v2.resize(M + 1);
		S = 0, E = 401;
		for (int i = 1; i <= N; i++) {
			cin >> v1[i].x1 >> v1[i].y1 >> v1[i].x2 >> v1[i].y2 >> v1[i].w;
			if (v1[i].x1 > v1[i].x2) swap(v1[i].x1, v1[i].x2);
			c[S][i] = 1;
			w[S].push_back(i);
			w[i].push_back(S);
		}
		for (int i = 1; i <= M; i++) {
			cin >> v2[i].x1 >> v2[i].y1 >> v2[i].x2 >> v2[i].y2 >> v2[i].w;
			if (v2[i].y1 > v2[i].y2) swap(v2[i].y1, v2[i].y2);
			c[200 + i][E] = 1;
			w[200 + i].push_back(E);
			w[E].push_back(200 + i);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (v1[i].x1 <= v2[j].x1 && v2[j].x1 <= v1[i].x2 && v2[j].y1 <= v1[i].y1 && v1[i].y1 <= v2[j].y2) {
					c[i][200 + j] = 1;
					d[i][200 + j] = -v1[i].w * v2[j].w;
					d[200 + j][i] = -d[i][200 + j];
					w[i].push_back(200 + j);
					w[200 + j].push_back(i);
				}
			}
		}
		pii result = networkFlow();
		cout << result.first << ' ' << -result.second << '\n';
		v1.clear();
		v2.clear();
		for (int i = 0; i < 402; i++) w[i].clear();
		memset(c, 0, sizeof c);
		memset(f, 0, sizeof f);
		memset(d, 0, sizeof d);
	}


	return 0;
}
