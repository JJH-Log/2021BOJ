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
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int par[100000];
vector<int> w[100000];
queue<int> q;
int N;

void dfs(int now, int parent) {
	par[now] = parent;
	for (auto next : w[now]) {
		if (next == parent) continue;
		dfs(next, now);
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
	dfs(0, -1);
	int parent = -1;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x; x--;
		if (parent != par[x]) {
			cout << 0;
			return 0;
		}
		cnt--; q.push(x);
		while (!cnt && !q.empty()) {
			int now = q.front();
			cnt = w[now].size();
			if (now) cnt--;
			parent = now;
			q.pop();
		}
	}
	cout << 1;

	return 0;
}
