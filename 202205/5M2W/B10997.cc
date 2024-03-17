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
#define MOD 1000000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, H, W, x, y, dir, cnt, lft;
int v[400][400];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	if (N == 1) {
		cout << '*';
		return 0;
	}

	H = 4 * N - 1;
	W = 4 * N - 3;
	x = 2 * N;
	y = 2 * (N - 1);
	dir = 0;
	cnt = 2;
	lft = (cnt / 2) * 2;

	while (x >= 0 && x < H && y >= 0 && y < W) {
		v[x][y] = 1;
		if (lft == 0) {
			cnt++;
			lft = (cnt / 2) * 2;
			dir = (dir + 1) % 4;
		}
		else {
			x = x + "0121"[dir] - '1';
			y = y + "1210"[dir] - '1';
			lft--;
		}
	}

	int idx;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) if (v[i][j]) idx = j;
		for (int j = 0; j <= idx; j++) cout << (v[i][j] ? '*' : ' ');
		cout << '\n';
	}


	return 0;
}