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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int d, x;
};
int H, W, N, res;
info v[100];
info now;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> W >> H >> N;
	for (int i = 0; i < N; i++) cin >> v[i].d >> v[i].x;
	cin >> now.d >> now.x;


	for (int i = 0; i < N; i++) {
		if (now.d == 1) {
			if (v[i].d == 1) res += abs(now.x - v[i].x);
			if (v[i].d == 2) res += H + W - abs((W - now.x) - v[i].x);
			if (v[i].d == 3) res += now.x + v[i].x;
			if (v[i].d == 4) res += W - now.x + v[i].x;
		}
		if (now.d == 2) {
			if (v[i].d == 1) res += H + W - abs((W - now.x) - v[i].x);
			if (v[i].d == 2) res += abs(now.x - v[i].x);
			if (v[i].d == 3) res += now.x + H - v[i].x;
			if (v[i].d == 4) res += W - now.x + H - v[i].x;
		}
		if (now.d == 3) {
			if (v[i].d == 1) res += now.x + v[i].x;
			if (v[i].d == 2) res += H - now.x + v[i].x;
			if (v[i].d == 3) res += abs(now.x - v[i].x);
			if (v[i].d == 4) res += H + W - abs((H - now.x) - v[i].x);
		}
		if (now.d == 4) {
			if (v[i].d == 1) res += now.x + W - v[i].x;
			if (v[i].d == 2) res += H - now.x + W - v[i].x;
			if (v[i].d == 3) res += H + W - abs((H - now.x) - v[i].x);
			if (v[i].d == 4) res += abs(now.x - v[i].x);
		}
	}
	cout << res;

	return 0;
}