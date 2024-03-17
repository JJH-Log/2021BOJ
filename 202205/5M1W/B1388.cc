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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, res;
string v[50];
bool vtd[50][50];

void dfs(int x, int y, char c) { //0: -, 1:|
	vtd[x][y] = true;
	if (c == '-') {
		for (int i = 0; i < 2; i++) {
			int dx = x;
			int dy = y + "20"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && !vtd[dx][dy] && v[dx][dy] == c) dfs(dx, dy, c);
		}
	}
	if (c == '|') {
		for (int i = 0; i < 2; i++) {
			int dx = x + "20"[i] - '1';
			int dy = y;
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && !vtd[dx][dy] && v[dx][dy] == c) dfs(dx, dy, c);
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vtd[i][j]) {
				res++;
				dfs(i, j, v[i][j]);
			}
		}
	}
	cout << res;
	
	return 0;
}
