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
#define BOUND 1000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 500005
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;



int N, M;
int x[10001], y[10001];
int xcnt, ycnt;
lld xtotal;
lld xres, yres;
lld ytotal;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int xt, yt;
		cin >> xt >> yt;
		x[xt]++, y[yt]++;
		xtotal += xt, ytotal += yt;
	}
	xres = 1e11; yres = 1e11;
	for (int i = 0; i <= N; i++) {
		xtotal -= (lld)M - 2 * xcnt;
		ytotal -= (lld)M - 2 * ycnt;
		xres = min(xres, xtotal);
		yres = min(yres, ytotal);
		if (i != N) {
			xcnt += x[i + 1];
			ycnt += y[i + 1];
		}
	}
	cout << xres + yres;
	return 0;
}