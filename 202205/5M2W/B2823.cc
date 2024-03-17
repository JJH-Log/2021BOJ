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

int R, C;
int v[12][12];
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		cin >> s;
		for (int j = 1; j <= C; j++) if (s[j - 1] == 'X') v[i][j] = 1;
	}
	for (int i = 1; i <= C; i++) v[0][i] = v[R + 1][i] = 1;
	for (int i = 1; i <= R; i++) v[i][0] = v[i][C + 1] = 1;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (v[i][j]) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int dx = i + "2011"[k] - '1';
				int dy = j + "1120"[k] - '1';
				if (v[dx][dy]) cnt++;
			}
			if (cnt >= 3) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;

	return 0;
}