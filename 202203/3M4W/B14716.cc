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

int N, M, res;
int v[250][250];
bool vtd[250][250];
queue<pos> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

void _push(int x, int y) {
	vtd[x][y] = 1;
	q.push({ x, y });
}

void bfs() {
	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int dx = now.x + "22210001"[i] - '1';
			int dy = now.y + "21000122"[i] - '1';
			if (inRange(dx, dy) && v[dx][dy] && !vtd[dx][dy]) _push(dx, dy);
		}
	}
}



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] && !vtd[i][j]) {
				res++;
				_push(i, j);
				bfs();
			}
		}
	}
	cout << res;

	return 0;
}