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

vector<vector<pair<int, int>>> w;
vector<int> v;
int N, M;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, k;
	cin >> N;
	w.resize(N, vector<pair<int, int>>(1, { 0, -1 }));
	v.resize(N, 0);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> k;
		x--, y--;
		w[x].push_back({ y, k });
		w[y][0].first++;
	}
	v[N - 1] = 1;
	q.push(N - 1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (w[now].size() == 1) continue;
		for (int i = 1; i < w[now].size(); i++) {
			int next = w[now][i].first;
			v[next] += v[now] * w[now][i].second;
			w[next][0].first--;
			if (!w[next][0].first) q.push(next);
		}
		v[now] = 0;
	}

	for (int i = 0; i < N; i++) if (v[i]) cout << i + 1 << ' ' << v[i] << '\n';


	return 0;
}