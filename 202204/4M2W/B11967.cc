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

struct pos {
	int x, y;
};

int N, M, res;
vector<pos> w[100][100];
bool vtd[100][100];
bool able[100][100];
queue<pos> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }


bool isNear(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (inRange(dx, dy) && vtd[dx][dy]) return true;
	}
	return false;
}

void _push(int x, int y) {
	vtd[x][y] = true;
	q.push({ x, y });
}

void check(int x, int y) {
	for (auto tar : w[x][y]) {
		if (!able[tar.x][tar.y]) {
			able[tar.x][tar.y] = true;
			res++;
		}
		if (isNear(tar.x, tar.y) && !vtd[tar.x][tar.y]) _push(tar.x, tar.y);
	}
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (inRange(dx, dy) && able[dx][dy] && !vtd[dx][dy]) _push(dx, dy);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	int a, b, c, d;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d; a--, b--, c--, d--;
		w[a][b].push_back({ c, d });
	}
	able[0][0] = true;
	res++;
	_push(0, 0);
	while (!q.empty()) {
		pos now = q.front(); q.pop();
		check(now.x, now.y);
	}
	cout << res;
	return 0;
}