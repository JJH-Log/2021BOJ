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

struct pos {
	int x, y;
};


pos d[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int N, x, y, dx, dy, dir, tar, now;
int v[1000][1000];
pos res;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> tar;
	x = y = dir = 0;
	now = N * N;
	while (now) {
		v[x][y] = now;
		if (now == tar) res = { x, y };
		if (now == 1) break;
		int dx = x + d[dir].x;
		int dy = y + d[dir].y;
		if (!inRange(dx, dy) || v[dx][dy]) dir = (dir + 1) % 4;
		else x = dx, y = dy, now--;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
	cout << res.x + 1 << ' ' << res.y + 1;
	
	return 0;
}
