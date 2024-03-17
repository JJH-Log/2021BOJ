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

struct info { int ti, used, before, x, y; };

int v[10][10];
bool isCross[10][10];
int N, M;
bool inQ[DEAD][2][2][10][10];
queue<info> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }
void check_push(int ti, int used, int before, int x, int y) {
	if (!inQ[ti][used][before][x][y]) {
		inQ[ti][used][before][x][y] = true;
		q.push({ ti, used, before, x, y });
	}
}

void checkCross() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == 0) {
				if (i != 0 && j != 0 && v[i - 1][j] == 0 && v[i][j - 1] == 0) isCross[i][j] = true;
				if (i != 0 && j != N - 1 && v[i - 1][j] == 0 && v[i][j + 1] == 0) isCross[i][j] = true;
				if (i != N - 1 && j != 0 && v[i + 1][j] == 0 && v[i][j - 1] == 0) isCross[i][j] = true;
				if (i != N - 1 && j != N - 1 && v[i + 1][j] == 0 && v[i][j + 1] == 0) isCross[i][j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	checkCross();
	inQ[0][0][0][0][0] = true;
	q.push({ 0,0,0,0,0 });

	while (!q.empty()) {
		info now = q.front();
		if (now.x == N - 1 && now.y == N - 1) {
			cout << now.ti;
			return 0;
		}
		q.pop();
		
		int dt = now.ti + 1;
		if (dt == DEAD) continue;
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy)) {
				if (v[dx][dy] == 1) check_push(dt, now.used, 0, dx, dy);
				if (v[dx][dy] > 1 && (dt % v[dx][dy] == 0) && (now.before == 0)) check_push(dt, now.used, 1, dx, dy);
				if (v[dx][dy] == 0 && (!isCross[dx][dy]) && (dt % M == 0) && (now.before == 0) && (now.used == 0)) check_push(dt, 1, 1, dx, dy);
			}
		}
		if (v[now.x][now.y] == 1) check_push(dt, now.used, 0, now.x, now.y);
	}
	
	return 0;
}
