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

int H, W, X, Y;
int v[600][600];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W >> X >> Y;
	for (int i = 0; i < H + X; i++) for (int j = 0; j < W + Y; j++) cin >> v[i][j];

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i >= X && j >= Y) v[i][j] -= v[i - X][j - Y];
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}