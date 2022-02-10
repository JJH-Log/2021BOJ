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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, M, X, Y, T;
int d[100];
vector<int> w[100];

void dfs(int now, int parent, int depth) {
	d[now] = depth;
	for (auto tar : w[now]) {
		if (tar != parent)  dfs(tar, now, depth + 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) d[i] = -1;
	cin >> X >> Y;
	X--, Y--;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dfs(X, -1, 0);
	cout << d[Y];
	return 0;
}
