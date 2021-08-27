#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<vector<int>> v;
vector<pair<int, int>> c;
vector<bool> lock;
vector<int> p;
queue<pair<int, int>> q1, q2;
int N, M, G, R, ls;

bool inRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

int simulate() {
	int i, j, x, y, dx, dy;
	int result = 0;
	vector<vector<int>> w = v;
	for (i = 0; i < G + R; i++) {
		x = c[p[i]].first, y = c[p[i]].second;
		if (i < G) w[x][y] = 3;
		else w[x][y] = 4;
		q1.push({ x, y });
	}
	while (true) {
		while (!q1.empty()) {
			x = q1.front().first;
			y = q1.front().second;
			q1.pop();
			for (i = 0; i < 4; i++) {
				dx = x + "2011"[i] - '1';
				dy = y + "1120"[i] - '1';
				if (inRange(dx, dy)) {
					if (w[dx][dy] == 1 || w[dx][dy] == 2) {
						w[dx][dy] = w[x][y] + 10;
						q2.push({ dx, dy });
					}
					else if (w[dx][dy] == 13 || w[dx][dy] == 14) {
						if (w[dx][dy] % 10 != w[x][y] % 10) {
							result++;
							w[dx][dy] = 9;
						}
					}
				}
			}
		}
		while (!q2.empty()) {
			x = q2.front().first;
			y = q2.front().second;
			q2.pop();
			if (w[x][y] > 10) w[x][y] -= 10, q1.push({ x, y });
		}
		if (q1.empty()) break;
	}

	return result;
}

int backTracking(int idx, int cnt) {
	int result = 0;
	if (cnt == G + R) return simulate();
	for (int i = idx; i < ls; i++) {
		if (!lock[i]) {
			lock[i] = true;
			p[cnt] = i;
			if(cnt == G - 1) result = max(result, backTracking(0, cnt + 1));
			else result = max(result, backTracking(i + 1, cnt + 1));
			lock[i] = false;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	cin >> N >> M >> G >> R;
	v.resize(N, vector<int>(M, 0));
	p.resize(G + R, 0);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) c.push_back({ i, j });
		}
	}
	ls = c.size();
	lock.resize(ls, false);
	cout << backTracking(0, 0);

	return 0;
}