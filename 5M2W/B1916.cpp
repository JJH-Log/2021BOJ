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

	int i, N, E, R, F; //Node, Edge, Root, Finish
	int a, b, s;
	pair<int, int> temp;

	cin >> N >> E;
	d.resize(N + 1, 2e9);
	v.resize(N + 1, vector<pair<int,int>>());
	for (i = 0; i < E; i++) {
		cin >> a >> b >> s;
		v[a].push_back({b, s});
	}
	cin >> R >> F;
	pq.push({ 0, R });
	d[R] = 0;
	while (!pq.empty()) {
		temp = pq.top();
		pq.pop();
		if (temp.first != d[temp.second]) continue;
		else {
			for (auto& it : v[temp.second]) {
				if (temp.first + it.second < d[it.first]) {
					d[it.first] = temp.first + it.second, pq.push({ d[it.first], it.first });
				}
			}
		}
	}
	cout << d[F];
	return 0;
}