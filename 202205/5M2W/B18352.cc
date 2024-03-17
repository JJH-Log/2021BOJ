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

int N, M, K, X;
vector<int> w[300001];
int dist[300001];
vector<int> res;
queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		w[x].push_back(y);
	}
	dist[X] = 1;
	q.push(X);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (dist[now] == K + 1) res.push_back(now);
		else {
			for (auto tar : w[now]) {
				if (!dist[tar]) {
					dist[tar] = dist[now] + 1;
					q.push(tar);
				}
			}
		}
	}
	if (!res.size()) cout << -1;
	else {
		sort(res.begin(), res.end());
		for (auto p : res) cout << p << ' ';
	}


	return 0;
}