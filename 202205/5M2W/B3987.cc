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

struct pos {
	int x, y, dir;
};

int N, M, res, res_dir;
string v[500];
pos X;

int simulation(pos S) {
	int ans = 1;

	while (ans < 1000000) {
		int dx = S.x + "0121"[S.dir] - '1';
		int dy = S.y + "1210"[S.dir] - '1';
		if (dx < 0 || dx >= N || dy < 0 || dy >= M || v[dx][dy] == 'C') return ans;
		if (v[dx][dy] == '/') {
			if (S.dir == 0) S.dir = 1;
			else if (S.dir == 1) S.dir = 0;
			else if (S.dir == 2) S.dir = 3;
			else S.dir = 2;
		}
		if (v[dx][dy] == '\\') {
			if (S.dir == 0) S.dir = 3;
			else if (S.dir == 3) S.dir = 0;
			else if (S.dir == 1) S.dir = 2;
			else S.dir = 1;
		}
		S = { dx, dy, S.dir };
		ans++;
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];
	cin >> X.x >> X.y;
	X.x--, X.y--;
	res = 0;

	for (int i = 0; i < 4; i++) {
		int ans = simulation({X.x, X.y, i});
		if (ans > res) {
			res_dir = i;
			res = ans;
		}
	}
	cout << "URDL"[res_dir] << '\n';
	if (res == 1000000) cout << "Voyager";
	else cout << res;


	return 0;
}