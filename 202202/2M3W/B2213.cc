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

int N;
int v[10000];
vector<int> w[10000];
vector<int> tr[10000][2];
int dp[10000][2];
vector<int> result;

void dfs(int now, int parent) {
	dp[now][1] = v[now];
	for (auto tar : w[now]) {
		if (tar == parent) continue;
		dfs(tar, now);
		dp[now][0] += max(dp[tar][0], dp[tar][1]);
		dp[now][1] += dp[tar][0];
	}
}

void dfs2(int now, int parent, bool FLAG) { //FLAG == 1 일 때 무조건 건너뛰기
	bool next;
	if (FLAG || (dp[now][1] < dp[now][0])) next = false;
	else {
		result.push_back(now);
		next = true;
	}
	for (auto tar : w[now]) {
		if (tar == parent) continue;
		dfs2(tar, now, next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y; x--, y--;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dfs(0, -1);
	dfs2(0, -1, false);
	cout << max(dp[0][0], dp[0][1]) << '\n';
	sort(result.begin(), result.end());
	for (auto now : result) cout << now + 1 << ' ';
	return 0;
}
