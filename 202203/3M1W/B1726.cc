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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int dir, x, y;
};

int v[100][100];
pii d[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int mark[4][100][100];
queue<info> q;
int N, M;
info S, E;

bool inRange(int x, int y) { return x >= 0 && x < N&& y >= 0 && y < M; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(mark, -1, sizeof(mark));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}
	int x, y, dir;
	cin >> S.x >> S.y >> S.dir;
	S.x--, S.y--, S.dir--;
	if (S.dir == 1 || S.dir == 2) S.dir ^= 3;
	cin >> E.x >> E.y >> E.dir;
	E.x--, E.y--, E.dir--;
	if (E.dir == 1 || E.dir == 2) E.dir ^= 3;

	mark[S.dir][S.x][S.y] = 0;
	q.push({ S.dir, S.x, S.y });
	while (!q.empty()) {
		info now = q.front();
		if (mark[E.dir][E.x][E.y] != -1) {
			cout << mark[E.dir][E.x][E.y];
			return 0;
		}
		q.pop();
		for (int i = 1; i <= 3; i++) {
			bool FLAG = true;
			int dx, dy;
			for (int j = 1; j <= i; j++) {
				dx = now.x + d[now.dir].first * j;
				dy = now.y + d[now.dir].second * j;
				FLAG = (FLAG && inRange(dx, dy) && v[dx][dy] == 0);
			}
			if (FLAG && mark[now.dir][dx][dy] == -1) {
				q.push({ now.dir, dx, dy });
				mark[now.dir][dx][dy] = mark[now.dir][now.x][now.y] + 1;
			}
		}
		int ddir = (now.dir + 1) % 4;
		if (mark[ddir][now.x][now.y] == -1) {
			q.push({ ddir, now.x, now.y });
			mark[ddir][now.x][now.y] = mark[now.dir][now.x][now.y] + 1;
		}
		ddir = (now.dir + 3) % 4;
		if (mark[ddir][now.x][now.y] == -1) {
			q.push({ ddir, now.x, now.y });
			mark[ddir][now.x][now.y] = mark[now.dir][now.x][now.y] + 1;
		}
	}

	return 0;
}
