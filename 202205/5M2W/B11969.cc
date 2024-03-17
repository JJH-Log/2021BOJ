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

int N, Q, X, x, y, w[3][100001];


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> X;
		for (int j = 0; j < 3; j++) w[j][i] = w[j][i - 1];
		w[X - 1][i]++;
	}
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		cout << w[0][y] - w[0][x - 1] << ' ' << w[1][y] - w[1][x - 1] << ' ' << w[2][y] - w[2][x - 1] << '\n';
	}

	return 0;
}