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

int N, M, K, res;
int v[20][20];
int pt[20][20];
bool vtd[20][20];
struct pos { int x, y; };
queue<pos> q, q2;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

void marking(pos S) {
	int tar = v[S.x][S.y];
	vtd[S.x][S.y] = true;
	q.push({ S.x, S.y });
	q2.push({ S.x, S.y });

	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && v[dx][dy] == tar && !vtd[dx][dy]) {
				vtd[dx][dy] = true;
				q.push({ dx, dy });
				q2.push({ dx, dy });
			}
		}
	}

	int score = q2.size() * tar;
	while (!q2.empty()) {
		pos now = q2.front(); q2.pop();
		pt[now.x][now.y] = score;
	}
}


struct dice {
	int d[6], dir;
	pos p;
	int move_op[4][4] = { {5,3,0,2}, {5,1,0,4}, {5,2,0,3}, {5,4,0,1} }; //right down left up

	pos next() {
		int dx = p.x + "1210"[dir] - '1';
		int dy = p.y + "2101"[dir] - '1';
		if (inRange(dx, dy)) return { dx, dy };
		else {
			dir = (dir + 2) % 4;
			return next();
		}
	}
	
	void swift() {
		int tmp[4];
		for (int i = 0; i < 4; i++) tmp[i] = move_op[dir][i];
		int dummy = d[tmp[3]];
		for (int i = 3; i; i--) d[tmp[i]] = d[tmp[i - 1]];
		d[tmp[0]] = dummy;
	}

	void move() {
		p = next();
		swift();
		res += pt[p.x][p.y];
		if (d[5] > v[p.x][p.y]) dir = (dir + 1) % 4;
		if (d[5] < v[p.x][p.y]) dir = (dir + 3) % 4;
	}
};


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	dice D;
	for (int i = 0; i < 6; i++) D.d[i] = i + 1;
	D.dir = 0; D.p = { 0, 0 };

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vtd[i][j]) marking({ i, j });
		}
	}

	for (int i = 0; i < K; i++) D.move();
	cout << res;

	return 0;
}