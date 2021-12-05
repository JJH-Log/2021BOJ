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

vector<vector<int>> w;
vector<int> v;
int N, R, Q;


int dfs(int now, int parent) {
	for (auto& next : w[now]) {
		if (next == parent) continue;
		v[now] += dfs(next, now);
	}
	return v[now];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> N >> R >> Q;
	w.resize(N);
	v.resize(N, 1);
	R--;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		x--, y--;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dfs(R, -1);
	for (int i = 0; i < Q; i++) {
		cin >> x;
		cout << v[x - 1] << '\n';
	}
	return 0;
}