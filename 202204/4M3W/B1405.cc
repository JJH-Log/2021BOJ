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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
double res, p[4];
bool vtd[30][30];

void solve(int cnt, int x, int y, double now_p) {
	if (cnt == N) {
		res += now_p;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int dx = x + "1120"[i] - '1';
		int dy = y + "2011"[i] - '1';
		if (!vtd[dx][dy]) {
			vtd[dx][dy] = true;
			solve(cnt + 1, dx, dy, now_p * p[i]);
			vtd[dx][dy] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(12);
	
	cin >> N >> p[0] >> p[1] >> p[2] >> p[3];
	for (int i = 0; i < 4; i++) p[i] /= 100;
	vtd[15][15] = true;
	solve(0, 15, 15, 1);
	cout << res;

	return 0;
}