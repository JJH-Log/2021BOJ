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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


vector<int> dist;
vector<int> ans;
vector<vector<pii>> w;
int N, M;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	w.resize(N);
	ans.resize(N, -1);
	dist.resize(N, 1e9);

	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		x--, y--;
		w[x].push_back({ y, d });
		w[y].push_back({ x, d });
	}
	
	dist[0] = 0;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();
		if (dist[now.second] != now.first) continue;
		for (auto tar : w[now.second]) {
			if (dist[tar.first] > dist[now.second] + tar.second) {
				dist[tar.first] = dist[now.second] + tar.second;
				ans[tar.first] = now.second;
				pq.push({ dist[tar.first] , tar.first });
			}
		}
	}
	cout << N - 1 << '\n';
	for (int i = 1; i < N; i++) cout << i + 1 << ' ' << ans[i] + 1 << '\n';

	return 0;
}
