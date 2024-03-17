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
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


struct pos {
	int x, y;
};

int N, M, T;
int v[1000][1000];
queue<pos> q;

void bfs(int sx, int sy) {
	q.push({ sx, sy });
	v[sx][sy] = 0;
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && v[dx][dy]) {
				v[dx][dy] = 0;
				q.push({ dx ,dy });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x, y, z;
			cin >> x >> y >> z;
			v[i][j] = x + y + z;
		}
	}
	cin >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) v[i][j] = (3 * T > v[i][j] ? 0 : v[i][j]);
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) if (v[i][j]) cnt++, bfs(i, j);
	}
	cout << cnt;


	return 0;
}