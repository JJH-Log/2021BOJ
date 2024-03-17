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


struct pos {
	int x, y, d;
	pos(int x, int y, int d) :x(x), y(y), d(d) {};
};

int N, v[101][101];
int xl, xr, yl, yr;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	pos now(50, 50, 0);
	v[50][50] = 1;
	xl = xr = 50;
	yl = yr = 50;
	cin >> N >> s;
	
	for (int i = 0; i < N; i++) {
		if (s[i] == 'R') now.d = (now.d + 1) % 4;
		if (s[i] == 'L') now.d = (now.d + 3) % 4;
		if (s[i] == 'F') {
			now.x = now.x + "2101"[now.d] - '1';
			now.y = now.y + "1012"[now.d] - '1';
			xl = min(xl, now.x); xr = max(xr, now.x);
			yl = min(yl, now.y); yr = max(yr, now.y);
			v[now.x][now.y] = 1;
		}
	}

	for (int i = xl; i <= xr; i++) {
		for (int j = yl; j <= yr; j++) cout << (v[i][j] ? '.' : '#');
		cout << '\n';
	}
	
	return 0;
}