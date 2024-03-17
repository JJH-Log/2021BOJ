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

string v[10];
int N, M, ans[10][10];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 'X') {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int dx = i + "2011"[k] - '1';
					int dy = j + "1120"[k] - '1';
					if (dx >= 0 && dx < N && dy >= 0 && dy < M && v[dx][dy] == 'X') cnt++;
				}
				if (cnt >= 2) ans[i][j] = 1;
			}
		}
	}

	int x1, y1, x2, y2;
	x1 = y1 = 11;
	x2 = y2 = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ans[i][j]) {
				x1 = min(x1, i);
				x2 = max(x2, i);
				y1 = min(y1, j);
				y2 = max(y2, j);
			}
		}
	}

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) cout << (ans[i][j] ? 'X' : '.');
		cout << '\n';
	}

	return 0;
}