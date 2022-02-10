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

int v[1000][1000]; //간선 사용 횟수, 현재 정점
vector<vector<pair<int, int>>> w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, M, K, S, D;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, d;
	cin >> N >> M >> K >> S >> D;
	S--, D--;
	w.resize(N);

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> d;
		x--, y--;
		w[x].push_back({ y, d });
		w[y].push_back({ x, d });
	}
	v[0][S] = 1, pq.push({ 1, S });

	while (!pq.empty()) {
		int road = pq.top().second / 1000;
		int now = pq.top().second % 1000;
		int dist = pq.top().first;
		pq.pop();
		if (dist == v[road][now] && (road != N - 1)) {
			for (auto next : w[now]) {
				if (!v[road + 1][next.first] || v[road + 1][next.first] > v[road][now] + next.second) {
					v[road + 1][next.first] = v[road][now] + next.second;
					pq.push({ v[road + 1][next.first] , (road + 1) * 1000 + next.first });
				}

			}
		}
	}

	lld result;
	int bidx, idx, tax;

	bidx = idx = N - 1, tax = 0;
	for (int i = 0; i < K + 1; i++) {
		if (i) {
			cin >> d;
			tax += d;
		}
		result = 1e10;
		for (int i = 0; i <= bidx; i++) if (v[i][D] && ((lld)v[i][D] + (tax * i) <= result)) result = (lld)v[i][D] + (tax * i), idx = i;
		cout << result  - 1<< '\n';
		bidx = idx;
	}

	return 0;
}