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
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos { int x, y; };

int getDist(pos a, pos b) { return abs(a.x - b.x) + abs(a.y - b.y); }

vector<pii> w[500005];
lld dist[500005];
pos v[100000], S;
int N;
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S.x >> S.y;
	for (int i = 0; i < N; i++) cin >> v[i].x >> v[i].y;
	
	for (int i = 1; i <= 5; i++) {
		int dx = v[0].x + "012011"[i] - '1';
		int dy = v[0].y + "011120"[i] - '1';
		w[0].push_back({ i, getDist(S, {dx, dy}) });
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j <= 5; j++) {
			int dx = v[i].x + "012011"[j] - '1';
			int dy = v[i].y + "011120"[j] - '1';
			for (int k = 1; k <= 5; k++) {
				int ddx = v[i + 1].x + "012011"[k] - '1';
				int ddy = v[i + 1].y + "011120"[k] - '1';
				w[5 * i + j].push_back({ 5 * i + 5 + k, getDist({dx, dy}, {ddx, ddy}) });
			}
		}
	}

	fill(dist, dist + 5 * N + 1, 1e12);
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

	lld res = 1e12;
	for (int i = 1; i <= 5; i++) res = min(res, dist[5 * (N - 1) + i]);
	cout << res;
	
	return 0;
}