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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N;
int res, w[10];
int v[20][20];

int simulation(int cnt) {
	vector<int> c(N, 0);
	for (int i = 0; i < cnt; i++) c[w[i]] = 1;
	int ans[2] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (c[i] == c[j]) ans[c[i]] += v[i][j] + v[j][i];
		}
	}
	return abs(ans[0] - ans[1]);
}

void backTracking(int idx, int cnt) {
	if (cnt == N / 2) {
		res = min(res, simulation(cnt));
		return;
	}
	for (int i = idx; i < N; i++) {
		w[cnt] = i;
		backTracking(i + 1, cnt + 1);
	}
	if(cnt) res = min(res, simulation(cnt));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	res = 1e9;
	backTracking(0, 0);
	cout << res;
	
	return 0;
}