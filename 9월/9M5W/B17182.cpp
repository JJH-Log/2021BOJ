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

int v[1 << 10][10], w[10][10];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> w[i][j];
	}
	v[1 << K][K] = 1;
	pq.push({ 1, (1 << K) * 10 + K });

	while (!pq.empty()) {
		int mask = pq.top().second / 10;
		int now = pq.top().second % 10;
		int dist = pq.top().first;
		pq.pop();
		if (dist == v[mask][now]) {
			for (int next = 0; next < N; next++) {
				if (!v[mask | (1 << next)][next] || (v[mask | (1 << next)][next] > v[mask][now] + w[now][next])) {
					v[mask | (1 << next)][next] = v[mask][now] + w[now][next];
					pq.push({ v[mask | (1 << next)][next] , (mask | (1 << next)) * 10 + next });
					
				}
			}
		}
	}
	int result = 1e9;
	for (int i = 0; i < N; i++) result = min(result, v[(1 << N) - 1][i]);
	cout << result - 1;

	return 0;
}