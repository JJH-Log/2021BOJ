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

vector<vector<pair<int,int>>> w;
vector<int> mcd, stb;
int V, E, M, S, mx, sx;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<int> dijkstra(vector<int> temp) {
	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();
		if (temp[now.second] != now.first) continue;
		for (auto next : w[now.second]) {
			if (temp[next.first] > temp[now.second] + next.second) {
				temp[next.first] = temp[now.second] + next.second;
				pq.push({ temp[next.first] , next.first });
			}
		}
	}
	return temp;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x, y, d;
	cin >> V >> E;
	w.resize(V);
	for (int i = 0; i < E; i++) {
		cin >> x >> y >> d;
		x--, y--;
		w[x].push_back({ y, d });
		w[y].push_back({ x, d });
	}
	vector<int> temp = vector<int>(V, 1e9 + 1);
	cin >> M >> mx;
	for (int i = 0; i < M; i++) {
		cin >> x, x--;
		temp[x] = 0;
		pq.push({ 0, x });
	}
	mcd = dijkstra(temp);

	temp = vector<int>(V, 1e9 + 1);
	cin >> S >> sx;
	for (int i = 0; i < S; i++) {
		cin >> x, x--;
		temp[x] = 0;
		pq.push({ 0, x });
	}
	stb = dijkstra(temp);

	int result = 2e9 + 1;
	for (int i = 0; i < V; i++) {
		if (mcd[i] && stb[i] && (mcd[i] <= mx) && (stb[i] <= sx)) {
			result = min(result, mcd[i] + stb[i]);
		}
	}
	if (result == 2e9 + 1) cout << -1;
	else cout << result;

	return 0;
}