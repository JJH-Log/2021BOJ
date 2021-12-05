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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

//REF : https://m.blog.naver.com/kks227/220810623254
vector<int> w[202];
int c[202][202], d[202][202], f[202][202];
int par[202]; //parent
int dst[202];
bool inQ[202];
queue<int> q;
int N, M;
int E = 201;
int S = 200;

void doFlow() {
	fill(par, par + 202, -1);
	fill(dst, dst + 202, BOUND);
	fill(inQ, inQ + 202, 0);

	dst[S] = 0;
	inQ[S] = true;
	q.push(S);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		inQ[now] = false;
		for (auto next : w[now]) {
			if (next == par[now]) continue;
			if (c[now][next] - f[now][next] > 0 && dst[next] > dst[now] + d[now][next]) {
				dst[next] = dst[now] + d[now][next];
				par[next] = now;
				if (!inQ[next]) {
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}
}

pii networkFlow() {
	int cnt = 0;
	int result = 0;
	while (true) {
		doFlow();
		if (par[E] == -1) break;
		int flow = BOUND;
		for (int now = E; now != S; now = par[now]) flow = min(flow, c[par[now]][now] - f[par[now]][now]);
		for (int now = E; now != S; now = par[now]) {
			result += flow * d[par[now]][now];
			f[par[now]][now] += flow;
			f[now][par[now]] -= flow;
		}
	}
	for (int i = 100; i < 100 + N; i++) cnt += f[i][E];
	return { cnt, result };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 100; i < 100 + N; i++) {
		cin >> c[i][E];
		w[E].push_back(i);
		w[i].push_back(E);
	}
	for (int i = 0; i < M; i++) {
		cin >> c[S][i];
		w[S].push_back(i);
		w[i].push_back(S);
	}
	for (int i = 0; i < M; i++) {
		for (int j = 100; j < 100 + N; j++) {
			cin >> c[i][j];
			if (c[i][j]) {
				w[i].push_back(j);
				w[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 100; j < 100 + N; j++) {
			cin >> d[i][j];
			d[j][i] = -d[i][j];
		}
	}
	pii result = networkFlow();
	cout << result.first << '\n' << result.second;
	
	return 0;
}
