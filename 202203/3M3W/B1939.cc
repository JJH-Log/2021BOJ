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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, S, E;
vector<pii> w[100001];
lld v[100001];

priority_queue<pii> pq;

void dijkstra() {
	v[S] = 1e9 + 1;
	pq.push({ v[S], S });
	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();
		if (now.first != v[now.second]) continue;
		for (auto next : w[now.second]) {
			if (v[next.first] < min(next.second, now.first)) {
				v[next.first] = min(next.second, now.first);
				pq.push({ v[next.first], next.first });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		w[x].push_back({ y , d });
		w[y].push_back({ x , d });
	}
	cin >> S >> E;
	dijkstra();
	cout << v[E];

	return 0;
}