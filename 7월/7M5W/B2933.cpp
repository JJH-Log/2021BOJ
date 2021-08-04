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
vector<vector<bool>> w;
queue<pair<int, int>> q;
int R, C;

int getNearest(int x, int y) {
	int nx = x;
	while (nx < R && !v[nx][y]) nx++;
	return nx - x - 1;
}

void mvMineral(vector<pair<int, int>> m) { //pair of mineral
	if (!m.size()) return;
	sort(m.begin(), m.end(), greater<pair<int, int>>());

	vector<bool> colCheck;
	colCheck.resize(C, false);

	int lowMove = R;
	for (auto& pos : m) {
		if (!colCheck[pos.second]) lowMove = min(lowMove, getNearest(pos.first, pos.second));
	}
	for (auto& pos : m) v[pos.first + lowMove][pos.second] = 1;
}


bool isInRange(int x, int y) {
	return (x >= 0) && (x < R) && (y >= 0) && (y < C);
}

vector<pair<int, int>> getFloatMineral() {
	vector<pair<int, int>> result;
	w.clear();
	w.resize(R, vector<bool>(C, false));
	int i, j, nx, ny, dx, dy;

	for (j = 0; j < C; j++) if (v[R - 1][j]) w[R - 1][j] = true, q.push({R - 1, j });
	while (!q.empty()) {
		nx = q.front().first;
		ny = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			dx = nx + "2011"[i] - '1';
			dy = ny + "1120"[i] - '1';
			if (isInRange(dx, dy) && !w[dx][dy] && v[dx][dy]) {
				w[dx][dy] = true;
				q.push({ dx, dy });
			}
		}
	}

	for (i = R - 1; i >= 0; i--) {
		for (j = 0; j < C; j++) {
			if (!w[i][j] && v[i][j]) v[i][j] = 0, result.push_back({ i, j });
		}
	}
	return result;
}

int scMineral(int x, int dir) {
	if (dir) for (int j = 0; j < C; j++) if (v[x][j]) return j;
	if (!dir) for (int j = C - 1; j >= 0; j--) if (v[x][j]) return j;
	return -1;
}

void printMineral() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (v[i][j]) cout << 'x';
			else cout << '.';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, temp, ans, dir;
	string s;
	cin >> R >> C;
	v.resize(R, vector<int>(C, 0));
	for (i = 0; i < R; i++) {
		cin >> s;
		for (j = 0; j < C; j++) if (s[j] == 'x') v[i][j] = 1;
	}

	cin >> N;
	dir = 1;
	for (i = 0; i < N; i++) {
		cin >> temp;
		ans = scMineral(R - temp, dir);
		dir ^= 1;
		if (ans == -1) continue;
		v[R - temp][ans] = 0;
		mvMineral(getFloatMineral());
	}
	printMineral();

	return 0;
}