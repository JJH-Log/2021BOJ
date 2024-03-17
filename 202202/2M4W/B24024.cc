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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct info {
	int tar, dist, color;
};

lld N, M, X;
vector<info> w[200000];
lld ans[200000];
priority_queue<pair<lld, lld>, vector<pair<lld, lld>>, greater<pair<lld, lld>>> pq;

lld weight(lld d, int c, lld p) {
	if (!c) return d;
	if (c == 1) return d + p;
	return d + X - p;
}

lld dijkstra(lld P) { // d+P if c==1, d+(X-P) if c==2
	fill(ans, ans + N, 1e15);
	ans[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		pair<lld, lld> now = pq.top();
		pq.pop();
		if (ans[now.second] != now.first) continue;
		for (auto tmp : w[now.second]) {
			if (ans[tmp.tar] > ans[now.second] + weight(tmp.dist, tmp.color, P)) {
				ans[tmp.tar] = ans[now.second] + weight(tmp.dist, tmp.color, P);
				pq.push({ ans[tmp.tar], tmp.tar });
			}
		}
	}
	return ans[N - 1];
}

pii solve(int lo, int hi) {
	if (hi - lo <= 5) return { lo, hi };
	int step, x1, x2;
	lld ans1, ans2;
	step = (hi - lo) / 3;
	x1 = lo + step, x2 = x1 + step;
	//cout << "LO, HI : " << lo << ' ' << hi << ' ' << x1 << ' ' << x2 <<  endl;
	ans1 = dijkstra(x1);
	ans2 = dijkstra(x2);
	if (ans1 < ans2) return solve(x1, hi);
	else if (ans1 > ans2) return solve(lo, x2);
	return solve(x1, x2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int x, y, d, c;
		cin >> x >> y >> d >> c;
		x--, y--;
		w[x].push_back({ y, d, c });
		w[y].push_back({ x, d, c });
	}
	//random_device rd;
	//mt19937 gen(rd());
	//uniform_int_distribution<int> dis(0, X);
	if (dijkstra(0) == dijkstra(X)) cout << dijkstra(0);
	else {
		pii ans = solve(0, X);
		lld result = 0;
		for (int i = ans.first; i <= ans.second; i++) result = max(result, dijkstra(i));
		cout << result;
	}
	
	return 0;
}
