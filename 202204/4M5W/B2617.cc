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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, res;
vector<int> w[2][101];
int sub[2][101];
bool vtd[2][101];

int dfs(int now, int op) {
	vtd[op][now] = true;
	int ans = 1;
	for (auto tar : w[op][now]) {
		if (vtd[op][tar]) continue;
		ans += dfs(tar, op);
	}
	return sub[op][now] = ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		w[0][x].push_back(y);
		w[1][y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			fill(vtd[j] + 1, vtd[j] + N + 1, false);
			dfs(i, j);
		}
		if (sub[0][i] > (N / 2) + 1 || sub[1][i] > (N / 2) + 1) res++;
	}
	cout << res;

	return 0;
}
