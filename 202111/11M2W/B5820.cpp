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

int N, K, result;
vector<vector<pii>> w;
int sz[200005];
bool kill[200005];
map<int, int> m;

int getSize(int now, int parent) {
	sz[now] = 1;
	for (auto next : w[now]) if (!kill[next.first] && next.first != parent) sz[now] += getSize(next.first, now);
	return sz[now];
}

int getCentroid(int now, int parent, int cap) {
	for (auto next : w[now]) if (!kill[next.first] && next.first != parent && sz[next.first] > cap) return getCentroid(next.first, now, cap);
	return now;
}

void find(int now, int parent, int dist, int depth) {
	if (dist > K) return;
	if (m.count(K - dist)) result = min(result, m[K - dist] + depth);
	for (auto next : w[now]) if (!kill[next.first] && next.first != parent) find(next.first, now, dist + next.second, depth + 1);
}

void update(int now, int parent, int dist, int depth) {
	if (dist > K) return;
	if (m.count(dist)) m[dist] = min(m[dist], depth);
	else m[dist] = depth;
	for (auto next : w[now]) if (!kill[next.first] && next.first != parent) update(next.first, now, dist + next.second, depth + 1);
}

void solve(int now) {
	int cap = getSize(now, -1) / 2;
	int center = getCentroid(now, -1, cap);
	kill[center] = true;
	m.clear(); m[0] = 0;
	for (auto next : w[center]) {
		if (!kill[next.first]) {
			find(next.first, center, next.second, 1);
			update(next.first, center, next.second, 1);
		}
	}
	for (auto next : w[center]) if (!kill[next.first]) solve(next.first);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	result = 1e9;
	w.resize(N);
	for (int i = 1; i < N; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		w[x].push_back({ y, d });
		w[y].push_back({ x, d });
	}
	solve(0);
	if (result == 1e9) cout << -1;
	else cout << result;

	return 0;
}
