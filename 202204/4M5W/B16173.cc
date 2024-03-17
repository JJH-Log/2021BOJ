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
#define MOD 1000000009
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

int N;
int v[64][64];
bool vtd[64][64];
queue<pos> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }

void _push(int x, int y) {
	vtd[x][y] = 1;
	q.push({ x, y });
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	_push(0, 0);

	while (!q.empty()) {
		pos now = q.front(); q.pop();
		if (v[now.x][now.y] == -1) break;
		for (int i = 0; i < 2; i++) {
			int dx = now.x + v[now.x][now.y] * ("21"[i] - '1');
			int dy = now.y + v[now.x][now.y] * ("12"[i] - '1');
			if (inRange(dx, dy) && !vtd[dx][dy]) _push(dx, dy);
		}
	}
	if (vtd[N - 1][N - 1]) cout << "HaruHaru";
	else cout << "Hing";
	
	return 0;
}