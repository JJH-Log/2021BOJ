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

vector<map<int,int>> v; //Node | cost, dist
vector<int> cost;
vector<int> cnt;
vector<string> road;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //dist | Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i, j;
	int x, y, d, td, tn;
	cin >> N >> M;
	v.resize(N + 1);
	cost.resize(N + 1, 1e9);
	cnt.resize(N + 1, 1e9);
	road.resize(N + 1, "");

	for (i = 0; i < M; i++) {
		cin >> x >> y >> d;
		if (!v[x].count(y)) v[x][y] = d;
		else v[x][y] = min(v[x][y], d);
	}
	cin >> x >> y;
	cost[x] = 0;
	cnt[x] = 1;
	road[x] = to_string(x) + " ";
	pq.push({ 0, x });
	while (!pq.empty()) {
		td = pq.top().first;
		tn = pq.top().second;
		pq.pop();
		if (td != cost[tn]) continue;
		for (auto it = v[tn].begin(); it != v[tn].end(); it++) {
			if (cost[tn] + it->second < cost[it->first]) {
				cost[it->first] = cost[tn] + it->second;
				cnt[it->first] = cnt[tn] + 1;
				road[it->first] = road[tn] + to_string(it->first) + " ";
				pq.push({ cost[it->first], it->first });
			}
		}
	}
	cout << cost[y] << "\n" << cnt[y] << "\n" << road[y];
	return 0;
}