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


int N, M, K;
lld res, dp[80][100][100];
string tar;
char v[100][100];

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

lld solve(int idx, int x, int y) {
	if (idx == tar.size()) return 1;
	lld& ans = dp[idx][x][y];
	if (ans != -1) return ans;
	ans = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < 4; j++) {
			int dx = x + i * ("2011"[j] - '1');
			int dy = y + i * ("1120"[j] - '1');
			if (inRange(dx, dy) && v[dx][dy] == tar[idx]) {
				ans += solve(idx + 1, dx, dy);
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(dp, -1, sizeof dp);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) v[i][j] = s[j];
	}
	cin >> tar;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == tar[0]) res += solve(1, i, j);
		}
	}
	cout << res;

	return 0;
}