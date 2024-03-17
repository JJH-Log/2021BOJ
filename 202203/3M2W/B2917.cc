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
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y;
};

struct info {
	int x, y, val;
};

struct cmp {
	bool operator()(info& A, info& B) {
		return A.val < B.val;
	}
};

int v[500][500];
int d[500][500];
int N, M;
pos V, J;
queue<pos> q;
priority_queue<info, vector<info>, cmp> pq;

bool inRange(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '+') v[i][j] = 0, q.push({ i, j });
			else v[i][j] = -1;
			if (s[j] == 'V') V = { i, j };
			if (s[j] == 'J') J = { i, j };
			d[i][j] = -1;
		}
	}
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && v[dx][dy] == -1) {
				v[dx][dy] = v[now.x][now.y] + 1;
				q.push({ dx, dy });
			}
		}
	}
	d[V.x][V.y] = v[V.x][V.y];
	pq.push({ V.x, V.y, d[V.x][V.y] });
	while (!pq.empty()) {
		info now = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (inRange(dx, dy) && d[dx][dy] == -1) {
				d[dx][dy] = min(v[dx][dy], d[now.x][now.y]);
				pq.push({ dx, dy, d[dx][dy] });
			}
		}
	}
	cout << d[J.x][J.y];

	return 0;
}
