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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


struct board {
	char v[5][9];
	int pin;
};

bool inRange(int x, int y) { return (x >= 0) && (x < 5) && (y >= 0) && (y < 9); }


board getNext(board now, int x, int y, int dx, int dy) {
	now.v[dx + dx - x][dy + dy - y] = 'o';
	now.pin--;
	now.v[x][y] = now.v[dx][dy] = '.';
	return now;
}

int solve(board now) {
	int ans = now.pin;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (now.v[i][j] == 'o') {
				for (int k = 0; k < 4; k++) {
					int dx = i + "2011"[k] - '1';
					int dy = j + "1120"[k] - '1';
					if (inRange(dx, dy) && inRange(dx + dx - i, dy + dy - j)
						&& now.v[dx][dy] == 'o'
						&& now.v[dx + dx - i][dy + dy - j] == '.') ans = min(ans, solve(getNext(now, i, j, dx, dy)));
				}
			}
		}
	}
	return ans;
}

board S;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		S.pin = 0;
		for (int i = 0; i < 5; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 9; j++) {
				S.v[i][j] = s[j];
				if (s[j] == 'o') S.pin++;
			}
		}
		int res = solve(S);
		cout << res << ' ' << S.pin - res << '\n';
	}

	return 0;
}