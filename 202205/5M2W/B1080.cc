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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, res;
string s;
int v[50][50];
int w[50][50];

void flip(int x, int y) {
	for (int i = 0; i < 9; i++) {
		int dx = x + "000111222"[i] - '1';
		int dy = y + "012012012"[i] - '1';
		v[dx][dy] ^= 1;
	}
}

bool isSame() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] != w[i][j]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) v[i][j] = s[j] - '0';
	}
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) w[i][j] = s[j] - '0';
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (v[i - 1][j - 1] != w[i - 1][j - 1]) {
				flip(i, j);
				res++;
			}
		}
	}
	if (!isSame()) cout << -1;
	else cout << res;

	return 0;
}