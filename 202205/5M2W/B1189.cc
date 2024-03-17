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

int R, C, K, res;
string v[5];

void go(int x, int y, int state, int cnt) {
	if (x == 0 && y == C - 1 && cnt == K) {
		res++;
		return;
	}
	if (cnt == K) return;
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (dx >= 0 && dx < R && dy >= 0 && dy < C) {
			int code = C * dx + dy;
			if ((state & (1 << code)) == 0 && v[dx][dy] != 'T') {
				go(dx, dy, state | (1 << code), cnt + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) cin >> v[i];
	go(R - 1, 0, (1 << ((R - 1) * C)), 1);
	cout << res;

	return 0;
}