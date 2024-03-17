#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1234567
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> w[10];
int dp[1001][10];
int T, N;

void connect(int x, int y) {
	w[x].push_back(y);
	w[y].push_back(x);
}

int solve(int left, int now) {
	int& res = dp[left][now];
	if (res != -1) return res;
	res = 0;
	for (auto tar : w[now]) res = (res + solve(left - 1, tar)) % MOD;
	return res;
}

void init_connect() {
	connect(1, 2); connect(1, 4); connect(2, 3);
	connect(2, 5); connect(3, 6); connect(4, 5);
	connect(4, 7); connect(5, 6); connect(5, 8);
	connect(6, 9); connect(7, 0); connect(7, 8); connect(8, 9);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init_connect();
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) dp[i][j] = -1;
	}
	for (int j = 0; j < 10; j++) dp[0][j] = 1;
	cin >> T;
	while (T--) {
		cin >> N;
		int res = 0;
		for (int i = 0; i < 10; i++) res = (res + solve(N - 1, i)) % MOD;
		cout << res << '\n';
	}

	return 0;
}