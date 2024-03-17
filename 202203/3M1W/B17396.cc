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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int lock[100000];
vector<pii> w[100000];
lld dist[100000];
int N, M;
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijkstra() {
	dist[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		pll now = pq.top();
		pq.pop();
		if (now.first != dist[now.second]) continue;
		for (auto tar : w[now.second]) {
			if (dist[tar.first] == -1 || dist[tar.first] > dist[now.second] + tar.second) {
				dist[tar.first] = dist[now.second] + tar.second;
				pq.push({ dist[tar.first], tar.first });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> lock[i];
	lock[N - 1] = 0;
	for (int i = 0; i < M; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		if (lock[x] || lock[y]) continue;
		w[x].push_back({ y, t });
		w[y].push_back({ x, t });

	}
	fill(dist, dist + N, -1);
	dijkstra();
	cout << dist[N - 1];

	return 0;
}
