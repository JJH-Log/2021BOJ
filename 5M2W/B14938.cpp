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

vector<vector<pair<int, int>>> v;
vector<int> item;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R, ans, result;
	int i, j, x, y, d;
	int tx, td;
	cin >> N >> M >> R;
	v.resize(N + 1);
	item.resize(N + 1);
	for (i = 1; i <= N; i++) cin >> item[i];
	for (i = 0; i < R; i++) {
		cin >> x >> y >> d;
		v[x].push_back({ y,d });
		v[y].push_back({ x,d });
	}
	result = 0;
	for (i = 1; i <= N; i++) {
		dist.clear();
		dist.resize(N + 1, 1000000);
		pq.push({ 0, i });
		dist[i] = 0;
		while (!pq.empty()) {
			td = pq.top().first;
			tx = pq.top().second;
			pq.pop();
			if (td != dist[tx]) continue;
			for (j = 0; j < v[tx].size(); j++) {
				if (dist[v[tx][j].first] > td + v[tx][j].second) {
					dist[v[tx][j].first] = td + v[tx][j].second;
					pq.push({ dist[v[tx][j].first] , v[tx][j].first });
				}
			}
		}
		ans = 0;
		for (j = 1; j <= N; j++) {
			if (dist[j] <= M) ans += item[j];
		}
		result = max(result, ans);
	}
	cout << result;
	return 0;
}