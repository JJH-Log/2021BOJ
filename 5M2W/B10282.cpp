#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<pair<int, int>>> v; //for edge | dist
vector<int> d; //for distance
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //dist|Node

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, T, N, E, R; //Node, Edge, Root
	int a, b, s, cnt, maxd;
	pair<int, int> temp;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N >> E >> R;
		d.resize(N + 1, 2e9);
		v.resize(N + 1, vector<pair<int,int>>());
		for (i = 0; i < E; i++) {
			cin >> a >> b >> s;
			v[b].push_back({a, s});
		}
		pq.push({ 0, R });
		maxd = 0, cnt = 1, d[R] = 0;
		while (!pq.empty()) {
			temp = pq.top();
			pq.pop();
			//cout << "POS : " << temp.first << " " << temp.second << endl;
			if (temp.first != d[temp.second]) continue;
			else {
				maxd = temp.first;
				for (auto& it : v[temp.second]) {
					if (temp.first + it.second < d[it.first]) {
						if (d[it.first] == 2e9) cnt++;
						d[it.first] = temp.first + it.second, pq.push({ d[it.first], it.first });
					}
				}
			}
		}
		cout << cnt << " " << maxd << "\n";
		d.clear();
		v.clear();
	}

	return 0;
}