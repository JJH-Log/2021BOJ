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

int N;
string v[1000];

int getMine(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		int dx = x + "00012221"[i] - '1';
		int dy = y + "01222100"[i] - '1';
		if (dx >= 0 && dx < N && dy >= 0 && dy < N && v[dx][dy] != '.') ans += v[dx][dy] - '0';
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] != '.') cout << '*';
			else {
				int ans = getMine(i, j);
				if (ans >= 10) cout << 'M';
				else cout << ans;
			}
		}
		cout << '\n';
	}

	return 0;
}
