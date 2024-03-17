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
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> w, wr;
vector<bool> vtd;
int N, M;

int dfs(int now, int dir) {
	int result = 1;
	vtd[now] = true;
	if (dir == 1) {
		for (auto& next : w[now]) {
			if (!vtd[next]) result += dfs(next, 1);
		}
	}
	else {
		for (auto& next : wr[now]) {
			if (!vtd[next]) result += dfs(next, 0);
		}
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int i, x, y, ans;
	w.resize(N);
	wr.resize(N);
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		x--, y--;
		w[x].push_back(y);
		wr[y].push_back(x);
	}
	for (i = 0; i < N; i++) {
		vtd.resize(N, 0);
		ans = N - (dfs(i, 1) + dfs(i, 0) - 1);
		cout << ans << '\n';
		vtd.clear();
	}
	return 0;
}