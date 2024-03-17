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

int x, y, N, v[102][102], res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) v[i][j] = 1;
		}
	}
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			if (v[i][j]) continue;
			for (int k = 0; k < 4; k++) {
				int dx = i + "2011"[k] - '1';
				int dy = j + "1120"[k] - '1';
				if (dx >= 0 && dx <= 101 && dy >= 0 && dy <= 101 && v[dx][dy]) res++;
			}
		}
	}
	cout << res;

	return 0;
}
