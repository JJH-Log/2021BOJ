#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>

#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> w;
vector<int> trace;

int nc[2003][2003], nf[2003][2003];
int N, M, K;


void doFlow(int start, int end) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto next : w[now]) {
			if (nc[now][next] - nf[now][next] > 0 && trace[next] == -1) {
				q.push(next);
				trace[next] = now;
				if (next == end) return;
			}
		}
	}
	return;
}

int maximumFlow(int start, int end) {
	int now, next, f, result;
	result = 0;
	while (true) {
		trace.clear();
		trace.resize(N + M + 3, -1);
		doFlow(start, end);
		if (trace[end] == -1) break;
		f = 1e9;
		for (now = end; now != start; now = trace[now]) f = min(f, nc[trace[now]][now] - nf[trace[now]][now]);
		for (now = end; now != start; now = trace[now]) {
			nf[trace[now]][now] += f;
			nf[now][trace[now]] -= f;
		}
		result += f;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x;
	cin >> N >> M >> K;

	w.resize(N + M + 3);

	nc[0][N + M + 2] = K;
	w[N + M + 2].push_back(0);
	w[0].push_back(N + M + 2);

	for (int i = 1; i <= N; i++) {
		nc[N + M + 2][i] = 1;
		nc[0][i] = 1;
		w[0].push_back(i);
		w[i].push_back(0);
		w[N + M + 2].push_back(i);
		w[i].push_back(N + M + 2);
	}
	for (int i = N + 1; i <= N + M; i++) {
		nc[i][N + M + 1] = 1;
		w[i].push_back(N + M + 1);
		w[N + M + 1].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> x;
			nc[i][N + x] = 1;
			w[i].push_back(N + x);
			w[N + x].push_back(i);
		}
	}
	cout << maximumFlow(0, N + M + 1);

	return 0;
}