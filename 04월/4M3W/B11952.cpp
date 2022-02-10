#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;


struct compare {
	bool operator()(pair<long long, int>a, pair<long long, int>b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};


vector<int> city; //1>: danger, 1: infected, , 0: safe
vector<long long> cost; //최단 경로 가격
queue<int> infected;
vector<vector<int>> g; //graph

priority_queue<pair<long long, int>, vector<pair<long long, int>>, compare> pq; //cost, target

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, S;
	int c1, c2;
	int x, y, d;
	int i, temp;

	cin >> N >> M >> K >> S;
	cin >> c1 >> c2;

	city.resize(N + 1, 0);
	cost.resize(N + 1, 0);
	g.resize(N + 1, vector<int>(0, 0));

	for (i = 0; i < K; i++) { cin >> temp;	city[temp] = 1; cost[temp] = -1; infected.push(temp); }
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	while (!infected.empty()) {
		temp = infected.front();
		infected.pop();
		if (city[temp] != S + 1) {
			for (i = 0; i < g[temp].size(); i++) {
				if (city[g[temp][i]] == 0) {
					city[g[temp][i]] = city[temp] + 1;
					infected.push(g[temp][i]);
				}
			}
		}
	}

	for (i = 0; i < g[1].size(); i++) {
		temp = city[g[1][i]];
		if (temp > 1) {
			cost[g[1][i]] = c2;
			pq.push(make_pair(c2, g[1][i]));
		}
		if (temp == 0) {
			cost[g[1][i]] = c1;
			pq.push(make_pair(c1, g[1][i]));
		}
	}

	city[1] = 1;
	int co1, co2;
	while (!pq.empty()) {
		pair<long long, int> tc = pq.top();
		//cout << "COST : " << tc.first << " TARGET : " << tc.second << endl;
		pq.pop();
		if (cost[tc.second] != tc.first) continue;
		city[tc.second] = 1;

		for (i = 0; i < g[tc.second].size(); i++) {
			//cout << "IM GOING TO :" << g[tc.second][i] << endl;
			temp = city[g[tc.second][i]];
			if (g[tc.second][i] == N) { co1 = 0; co2 = 0; }
			else { co1 = c1; co2 = c2; }

			if (temp > 1) {
				if ((cost[g[tc.second][i]] == 0) || (cost[tc.second] + co2 < cost[g[tc.second][i]])) {
					cost[g[tc.second][i]] = cost[tc.second] + co2;
					if(co2) pq.push(make_pair(cost[g[tc.second][i]], g[tc.second][i]));
				}
			}
			if (temp == 0) {
				if ((cost[g[tc.second][i]] == 0) || (cost[tc.second] + co1 < cost[g[tc.second][i]])) {
					cost[g[tc.second][i]] = cost[tc.second] + co1;
					if(co1) pq.push(make_pair(cost[g[tc.second][i]], g[tc.second][i]));
				}
			}
		}


	}
	
	cout << cost[N];
	return 0;
}
