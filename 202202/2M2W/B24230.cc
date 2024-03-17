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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

vector<int> w[200001];
int c[200001];
int N;
int res;

void dfs(int parent, int now) {
	if (c[parent] != c[now]) res++;
	for (auto tar : w[now]) {
		if (tar == parent) continue;
		dfs(now, tar);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> c[i];
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	res = 0;
	dfs(0, 1);
	cout << res;
	return 0;
}
