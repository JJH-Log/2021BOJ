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
#define MOD 1000000007
#define BOUND 1000000000
#define MAXN 200005
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


pii v[300000];
priority_queue<pii> pq;
int N, t, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		pq.push({ -v[i].first, 1 });
		pq.push({ -v[i].second, -1 });
	}

	int cnt = 0;
	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();
		cnt += now.second;
		if (cnt > res) res = cnt, t = now.first;
	}
	t = -t;
	cout << res << '\n';
	for (int i = 0; i < N; i++) {
		if (v[i].first <= t && t <= v[i].second) cout << i + 1 << ' ';
	}


	

	return 0;
}
