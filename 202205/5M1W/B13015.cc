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

int N, v[500][500];
pos c, l, r;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	c = { N - 1, 2 * N - 2 };
	l = { N - 1, 2 * N - 2 - (N - 1)};
	r = { N - 1, 2 * N - 2 + (N - 1)};
	for (int i = 0; i < N; i++) {
		v[l.x - i][l.y - i] = v[l.x + i][l.y - i] = 1;
		v[c.x - i][c.y - i] = v[c.x + i][c.y - i] = v[c.x - i][c.y + i] = v[c.x + i][c.y + i] = 1;
		v[r.x - i][r.y + i] = v[r.x + i][r.y + i] = 1;
	}
	for (int i = 1; i <= N - 2; i++) {
		v[0][i] = v[2 * N - 2][i] = 1;
		v[0][4 * N - 4 - i] = v[2 * N - 2][4 * N - 4 - i] = 1;
	}

	int t = 4 * N - 3;
	for (int i = 0; i < 2 * N - 1; i++) {
		for (int j = 0; j < t; j++) cout << (v[i][j] ? '*' : ' ');
		cout << '\n';
		if (i < N - 1) t--;
		else t++;
	}

	return 0;
}
