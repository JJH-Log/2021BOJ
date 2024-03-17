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

int M, N;
int c[1102][1102];
int f[1102][1102];
vector<int> w[1102];
vector<int> key[1000];
int S, E;
int par[1102];

void connect(int x, int y, int d) {
	w[x].push_back(y);
	w[y].push_back(x);
	c[x][y] = d;
}

void doFlow() {
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto tar : w[now]) {
			if (c[now][tar] - f[now][tar] > 0 && par[tar] == -1) {
				q.push(tar);
				par[tar] = now;
				if (tar == E) return;
			}
		}
	}
	return;
}

int maximumFlow() {
	int result = 0;
	while (true) {
		fill(par, par + 1102, -1);
		doFlow();
		if (par[E] == -1) break;
		int flow = 1e9;
		for (int now = E; now != S; now = par[now]) flow = min(flow, c[par[now]][now] - f[par[now]][now]);
		for (int now = E; now != S; now = par[now]) {
			f[par[now]][now] += flow;
			f[now][par[now]] -= flow;
		}
		result += flow;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> M >> N;
	S = 1100; E = 1101;

	for (int i = 0; i < M; i++) {
		cin >> x;
		connect(100 + i, E, x);
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> y; y--;
			connect(i, 100 + y, 1e9);
			for (auto tar : key[y]) connect(i, tar, 1e9);
			key[y].push_back(i);
		}
		cin >> x;
		connect(S, i, x);
	}
	cout << maximumFlow();

	return 0;
}
