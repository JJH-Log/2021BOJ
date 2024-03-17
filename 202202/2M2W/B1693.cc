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
#define BOUND 15
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

vector<int> w[100000];
int dp[100000][15];
int N;

int getMin(int tar, int x) {
	int ans = 1e9;
	for (int i = 0; i < 15; i++) if (i != x) ans = min(ans, dp[tar][i]);
	return ans;
}

void dfs(int parent, int now) {
	for (int i = 0; i < 15; i++) dp[now][i] = i + 1;
	for (auto tar : w[now]) {
		if (tar == parent) continue;
		if (!dp[tar][0]) dfs(now, tar);
		for (int i = 0; i < 15; i++) dp[now][i] += getMin(tar, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dfs(-1, 0);
	cout << getMin(0, -1);

	return 0;
}
