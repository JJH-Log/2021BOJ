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
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> w[2][500];
int N, M, res;
bool vtd[500];

int dfs(int t, int now){
	vtd[now] = 1;
	int ans = 1;
	for(auto next : w[t][now]){
		if(!vtd[next]) ans += dfs(t, next);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int x, y;
		cin >> x >> y; x--, y--;
		w[0][x].push_back(y);
		w[1][y].push_back(x);
	}
	for (int i = 0; i < N; i++){
		fill(vtd, vtd + N, 0);
		int ans = dfs(0, i) + dfs(1, i);
		if(ans == N + 1) res++;
	}
	cout << res;

	return 0;
}