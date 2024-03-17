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


int N, M, K;
lld cost[301][301];
int w[301][301];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		if (x > y) continue;
		w[x][y] = max(w[x][y], d);
	}
	cost[1][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (w[i][j]) {
				for (int k = 0; k < M; k++) {
					if (!cost[i][k]) continue;
					cost[j][k + 1] = max(cost[j][k + 1], cost[i][k] + w[i][j]);
				}
			}
		}
	}
	lld res = 0;
	for (int i = 1; i < M; i++) res = max(res, cost[N][i]);
	cout << res - 1;

	return 0;
}
