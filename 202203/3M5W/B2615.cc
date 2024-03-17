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

int v[30][30];
int dp[4][30][30];

int check(int op, int x, int y, int cnt) {
	int dx = x + "2210"[op] - '1';
	int dy = y + "1222"[op] - '1';
	if (v[x][y] != v[dx][dy]) return dp[op][x][y] = cnt;
	else return dp[op][x][y] = check(op, dx, dy, cnt + 1);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 5; i < 24; i++) {
		for (int j = 5; j < 24; j++) cin >> v[i][j];
	}

	for (int j = 5; j < 24; j++) {
		for (int i = 5; i < 24; i++) {
			if (v[i][j]) {
				for (int k = 0; k < 4; k++) {
					if (dp[k][i][j]) continue;
					if (check(k, i, j, 1) == 5) {
						cout << v[i][j] << '\n';
						cout << i - 4 << ' ' << j - 4;
						return 0;
					}
				}
			}
		}
	}
	cout << 0;
	return 0;
}