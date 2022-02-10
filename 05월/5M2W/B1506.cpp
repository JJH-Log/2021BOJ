#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<pair<int, int>>> v; //Node | Dist
int N;

int dijkstra(int A, int B) {
	if (A == B) return 0;

	vector<int> dist;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Dist | Node
	int i, FLAG, d, n;
	pair<int, int> temp;
	dist.resize(N + 1, 2e9);

	dist[A] = 0;
	for (i = 0; i < v[A].size(); i++) dist[v[A][i].first] = v[A][i].second, pq.push({ v[A][i].second, v[A][i].first });
	FLAG = 1;
	while (!pq.empty() && FLAG) {
		d = pq.top().first;
		n = pq.top().second;
		pq.pop();
		if (n == B) FLAG = 0;
		else {
			if (dist[n] != d) continue;
			else {
				for (i = 0; i < v[n].size(); i++) {
					if (dist[v[n][i].first] > d + v[n][i].second) dist[v[n][i].first] = d + v[n][i].second, pq.push({ dist[v[n][i].first], v[n][i].first });
				}
			}
		}
	}
	if (!FLAG) return d;
	return -1;
}

int total(int A, int B, int C) {
	if (A == -1 || B == -1 || C == -1) return 2e9;
	return A + B + C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, E, a, b, d;
	int v1, v2, result;
	cin >> N >> E;
	v.resize(N + 1);
	for (i = 0; i < E; i++) {
		cin >> a >> b >> d;
		v[a].push_back({ b, d });
		v[b].push_back({ a, d });
	}
	cin >> v1 >> v2;
	result = 2e9;
	int rr[3] = { dijkstra(1, v1), dijkstra(v1, v2), dijkstra(v2, N) };
	result = min(result, total(rr[0], rr[1], rr[2]));
	int rrr[3] = { dijkstra(1, v2), dijkstra(v2, v1), dijkstra(v1, N) };
	result = min(result, total(rrr[0], rrr[1], rrr[2]));
	if (result == 2e9) cout << "-1";
	else cout << result;
	return 0;
}