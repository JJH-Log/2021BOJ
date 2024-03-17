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

struct shark {
	int dir, x, y;
	void setPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void setPosDir(int dir, int x, int y) {
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
};

struct area {
	int id, num, time;
};

area v[20][20];
int tmp[20][20];
shark S[401];
int prio[401][5][5];
int N, M, K, cnt;
pii d[5] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool inRange(int x, int y) { return x >= 0 && x < N&& y >= 0 && y < N; }

//냄새 뿌리기 -> 이동 -> 냄새 깎기
void spreadSmell() {
	for (int i = 1; i <= M; i++) {
		if (S[i].x == -1) continue;
		int x = S[i].x;
		int y = S[i].y;
		v[x][y].num = i;
		v[x][y].time = K;
	}
}

void moveShark(int tar) {
	shark now = S[tar];

	for (int i = 1; i <= 4; i++) {
		int ddir = prio[tar][now.dir][i];
		int dx = now.x + d[ddir].first;
		int dy = now.y + d[ddir].second;
		if (inRange(dx, dy) && v[dx][dy].num == 0) {
			S[tar].setPosDir(ddir, dx, dy);
			if (tmp[dx][dy] == 0) tmp[dx][dy] = tar;
			else {
				S[tar].x = -1;
				cnt--;
			}
			return;
		}
	}

	for (int i = 1; i <= 4; i++) {
		int ddir = prio[tar][now.dir][i];
		int dx = now.x + d[ddir].first;
		int dy = now.y + d[ddir].second;
		if (inRange(dx, dy) && v[dx][dy].num == tar) {
			S[tar].setPosDir(ddir, dx, dy);
			if (tmp[dx][dy] == 0) tmp[dx][dy] = tar;
			else {
				S[tar].x = -1;
				cnt--;
			}
			return;
		}
	}
}
void printTMP() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << tmp[i][j] << ' ';
		cout << '\n';
	}
}

void subSmell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j].time) {
				v[i][j].time--;
				if (!v[i][j].time) v[i][j].num = 0;
			}
		}
	}
}

void moveSharks() {
	for (int i = 1; i <= M; i++) {
		if (S[i].x == -1) continue;
		moveShark(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp[i][j]) {
				v[i][j].id = tmp[i][j];
				tmp[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j].id;
			if (v[i][j].id) S[v[i][j].id].setPos(i, j);
		}
	}
	for (int i = 1; i <= M; i++) cin >> S[i].dir;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) cin >> prio[i][j][k];
		}
	}
	int time = 0;
	cnt = M;
	while (time <= 1000 && cnt != 1) {
		spreadSmell();
		moveSharks();
		subSmell();
		time++;
	}
	if (time == 1001) cout << -1;
	else cout << time;

	return 0;
}
