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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


lld dist[200000];
int note[200000], clt[200000];
vector<pll> w[200000];
int N, M;
priority_queue<pll, vector<pll>, greater<pll>> pq;
priority_queue<pll> pq2;
queue<int> q;

void dijkstra() {
	dist[0] = 0;
	pq.push({ dist[0], 0 });
	while (!pq.empty()) {
		pll now = pq.top(); pq.pop();
		if (dist[now.second] != now.first) continue;
		for (auto next : w[now.second]) {
			if (dist[next.first] > dist[now.second] + next.second) {
				dist[next.first] = dist[now.second] + next.second;
				pq.push({ dist[next.first], next.first });
			}
		}
	}
}

void dijkstra2() {
	clt[N - 1] = note[N - 1];
	pq2.push({ clt[N - 1], N - 1 });
	while (!pq2.empty()) {
		pll now = pq2.top(); pq2.pop();
		if (clt[now.second] != now.first) continue;
		for (auto next : w[now.second]) {
			if (dist[now.second] == dist[next.first] + next.second && clt[next.first] < clt[now.second] + note[next.first]) {
				clt[next.first] = clt[now.second] + note[next.first];
				pq2.push({ clt[next.first], next.first });
			}
		}
	}
}

bool FLAG;
void dfs(int now) {
	q.push(now);
	if (now == N - 1) FLAG = true;
	for (auto next : w[now]) {
		if (FLAG) continue;
		if (dist[now] + next.second == dist[next.first] && clt[now] - note[now] == clt[next.first]) dfs(next.first);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		dist[i] = 1e16;
		clt[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d; x--, y--;
		w[x].push_back({ y, d });
		w[y].push_back({ x, d });
	}
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> note[i];
		total += note[i];
	}
	dijkstra();
	dijkstra2();

	if (clt[0] != total) cout << -1;
	else {
		dfs(0);
		cout << q.size() << '\n';
		while (!q.empty()) {
			cout << q.front() + 1 << ' ';
			q.pop();
		}
	}

	return 0;
}