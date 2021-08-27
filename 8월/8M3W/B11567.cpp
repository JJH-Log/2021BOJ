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

vector<vector<bool>> v; //visited
queue<pair<int, int>> q;
int N, M;

bool check(int dx, int dy) {
	return dx >= 0 && dx < N&& dy >= 0 && dy < M && !v[dx][dy];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	string s;
	int x, y, dx, dy;
	int ex, ey;
	cin >> N >> M;
	v.resize(N, vector<bool>(M, false));
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++) if (s[j] == 'X') v[i][j] = true;
	}
	cin >> x >> y;
	v[x - 1][y - 1] = true;
	q.push({ x - 1, y - 1 });
	cin >> ex >> ey;
	ex--, ey--;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			dx = x + "2011"[i] - '1';
			dy = y + "1120"[i] - '1';
			if (dx == ex && dy == ey) {
				if (v[ex][ey]) {
					cout << "YES";
					return 0;
				}
				else {
					v[ex][ey] = true;
					q.push({ ex, ey });
				}
			}
			if (check(dx, dy)) {
				v[dx][dy] = true;
				q.push({ dx, dy });
			}
		}
	}
	cout << "NO";
	return 0;
}