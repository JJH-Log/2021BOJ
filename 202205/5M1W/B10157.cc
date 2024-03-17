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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y;
};

int R, C, K, dir, num;
bool vtd[1001][1001];
pos d[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
pos now;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	now = { 1, 1 };
	num = 1, dir = 0;
	cin >> R >> C >> K;
	if (R * C < K) cout << 0;
	else {
		while (num != K) {
			vtd[now.x][now.y] = true;
			int dx = now.x + d[dir].x;
			int dy = now.y + d[dir].y;
			if (dx >= 1 && dx <= R && dy >= 1 && dy <= C && !vtd[dx][dy]) {
				now = { dx, dy };
				num++;
			}
			else dir = (dir + 1) % 4;
		}
		cout << now.x << ' ' << now.y;
	}

	return 0;
}