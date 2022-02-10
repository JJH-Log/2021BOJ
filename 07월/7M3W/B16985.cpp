#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXLEN 10000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;


int maze[5][5][5];
int v[5][5][5] = { 0, };
int check[5] = { 0, };
pair<int, int> w[5];
queue<vector<int>> q;

bool isInBound(int h, int x, int y) {
	return (h >= 0 && h < 5 && x >= 0 && x < 5 && y >= 0 && y < 5);
}

int simulation() {
	int now, i;
	int h, x, y, dh, dx, dy;

	for (i = 0; i < 5; i++) {
		now = w[i].first;
		for (x = 0; x < 5; x++) {
			for (y = 0; y < 5; y++) {
				if (w[i].second == 0) v[i][x][y] = maze[now][x][y];
				if (w[i].second == 1) v[i][x][y] = maze[now][y][4 - x];
				if (w[i].second == 2) v[i][x][y] = maze[now][4 - x][4 - y];
				if (w[i].second == 3) v[i][x][y] = maze[now][4 - y][x];
			}
		}
	}
	if (!v[0][0][0] || !v[4][4][4]) return 1e9;
	v[0][0][0] = 2;
	q.push({ 0, 0, 0 });
	
	while (!q.empty()) {
		h = q.front()[0];
		x = q.front()[1];
		y = q.front()[2];
		q.pop();
		for (i = 0; i < 6; i++) {
			dh = h + "111120"[i] - '1';
			dx = x + "112011"[i] - '1';
			dy = y + "201111"[i] - '1';
			if (isInBound(dh, dx, dy) && v[dh][dx][dy] == 1) {
				v[dh][dx][dy] = v[h][x][y] + 1;
				q.push({ dh, dx, dy });
			}
		}
	}
	if (v[4][4][4] == 1) return 1e9;
	return v[4][4][4] - 2;
}

int selectDir(int cnt) {
	int result = 1e9;
	if (cnt == 5) return simulation();
	for (int i = 0; i < 4; i++) {
		w[cnt].second = i;
		result = min(result, selectDir(cnt + 1));
		if (result == 12) return 12;
	}
	return result;
}

int selectPos(int cnt) {
	int result = 1e9;
	if (cnt == 5) return selectDir(0);
	for (int i = 0; i < 5; i++) {
		if (!check[i]) {
			check[i] = 1;
			w[cnt].first = i;
			result = min(result, selectPos(cnt + 1));
			if (result == 12) return 12;
			check[i] = 0;
		}
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = -1;
	for (int t = 0; t < 5; t++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> maze[t][i][j];
			}
		}
	}
	result = selectPos(0);
	if (result != 1e9) cout << result;
	else cout << -1;
	return 0;
}