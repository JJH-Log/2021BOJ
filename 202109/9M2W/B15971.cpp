#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 100000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<pair<int, int>>> w;
int N, result;

void dfs(int now, int parent, int tar, int cost, int best) {
	if (now == tar) result = cost - best;
	for (auto& next : w[now]) {
		if ((result == -1) && next.first != parent) dfs(next.first, now, tar, cost + next.second, max(best, next.second));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, x, y, d;
	cin >> N >> A >> B;
	A--, B--;
	w.resize(N);
	for (int i = 1; i < N; i++) {
		cin >> x >> y >> d;
		x--, y--;
		w[x].push_back({ y,d });
		w[y].push_back({ x,d });
	}
	result = -1;
	dfs(A, -1, B, 0, 0);
	cout << result;
	return 0;
}