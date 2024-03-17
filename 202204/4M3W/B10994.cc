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

int N, v[400][400];

void fill(int x, int y) {
	for (int i = x; i <= y; i++) {
		v[x][i] = 1;
		v[i][x] = 1;
		v[i][y] = 1;
		v[y][i] = 1;
	}
	if (x != y) fill(x + 2, y - 2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	fill(0, 4 * N - 4);
	for (int i = 0; i <= 4 * N - 4; i++) {
		for (int j = 0; j <= 4 * N - 4; j++) cout << (v[i][j] ? '*' : ' ');
		cout << '\n';
	}



	return 0;
}