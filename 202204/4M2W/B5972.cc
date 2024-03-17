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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<pii> w[50000];
int dist[50000];
int N, M;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	int x, y, d;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> d; x--, y--;
		w[x].push_back({ y, d });
		w[y].push_back({ x, d });
	}
	for (int i = 0; i < N; i++) dist[i] = 1e9;
	dist[0] = 0;
	pq.push({ dist[0], 0 });

	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();
		if (now.first != dist[now.second]) continue;
		for (auto tar : w[now.second]) {
			if (dist[tar.first] > dist[now.second] + tar.second) {
				dist[tar.first] = dist[now.second] + tar.second;
				pq.push({ dist[tar.first], tar.first });
			}
		}
	}
	cout << dist[N - 1];
	
	return 0;
}