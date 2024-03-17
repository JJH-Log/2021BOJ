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

struct info{
	int tar, cost;
};

struct cmp{
	bool operator()(info a, info b){
		return a.cost > b.cost;
	}
};

int V, E, P;
vector<info> w[5001];
int dist[5001];
bool vtd[5001];
priority_queue<info, vector<info>, cmp> pq;
queue<int> q;

void dijkstra(){
	fill(dist, dist + V + 1, 1e9);
	dist[1] = 0;
	pq.push({1, dist[1]});
	while(!pq.empty()){
		info now = pq.top(); pq.pop();
		if(dist[now.tar] != now.cost) continue;
		for(auto next : w[now.tar]){
			if(dist[next.tar] > now.cost + next.cost){
				dist[next.tar] = now.cost + next.cost;
				pq.push({next.tar, dist[next.tar]});
			}
		}
	}
}

void bfs(){
	vtd[V] = true;
	q.push(V);
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto next : w[now]){
			if(!vtd[next.tar] && dist[next.tar] == dist[now] - next.cost){
				vtd[next.tar] = true;
				q.push(next.tar);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> P;
	for (int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		w[a].push_back({b, c});
		w[b].push_back({a, c});
	}
	dijkstra();
	bfs();
	cout << (vtd[P] ? "SAVE HIM" : "GOOD BYE");

	return 0;
}