#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<pii> w[10001];
int dist[10001];
int N, D;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> D;
	for (int i = 0; i < D; i++) w[i].push_back({ i + 1, 1 });
	for (int i = 0; i < N; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		w[x].push_back({ y, d });
	}
	fill(dist, dist + D + 1, 1e9);

	dist[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();
		if (now.first != dist[now.second]) continue;
		for (auto tar : w[now.second]) {
			if (dist[tar.first] > dist[now.second] + tar.second) {
				dist[tar.first] = dist[now.second] + tar.second;
				pq.push({ dist[tar.first] , tar.first });
			}
		}
	}
	cout << dist[D];
	
	return 0;
}