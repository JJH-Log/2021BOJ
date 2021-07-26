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
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<int>> w;
int N, M, C;

void paint(int x, int y, int d) {
	int dx = "2011"[d] - '1';
	int dy = "1120"[d] - '1';
	if (!v[x][y]) v[x][y] = 7;
	x += dx, y += dy;
	if (x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 6) paint(x, y, d);
	return;
}

int count() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!v[i][j]) cnt++;
		}
	}
	return cnt;
}

int simulation() {
	vector<vector<int>> backup = v;
	int i, x, y, d, result;
	for (i = 0; i < C; i++) {
		x = w[i][0];
		y = w[i][1];
		d = w[i][2];
		if (v[x][y] == 1) paint(x, y, d);
		else if (v[x][y] == 2) {
			if (d < 2) paint(x, y, 0), paint(x, y, 1);
			else paint(x, y, 2), paint(x, y, 3);
		}
		else if (v[x][y] == 3) {
			if (d == 0) paint(x, y, 0), paint(x, y, 2);
			else if (d == 1) paint(x, y, 0), paint(x, y, 3);
			else if (d == 2) paint(x, y, 1), paint(x, y, 2);
			else if (d == 3) paint(x, y, 1), paint(x, y, 3);
		}
		else if (v[x][y] == 4) {
			if (d == 0) paint(x, y, 0), paint(x, y, 2), paint(x, y, 3);
			else if (d == 1) paint(x, y, 1), paint(x, y, 2), paint(x, y, 3);
			else if (d == 2) paint(x, y, 0), paint(x, y, 1), paint(x, y, 2);
			else if (d == 3) paint(x, y, 0), paint(x, y, 1), paint(x, y, 3);
		}
		else if (v[x][y] == 5) paint(x, y, 0), paint(x, y, 1), paint(x, y, 2), paint(x, y, 3);
	}
	result = count();
	v = backup;
	return result;
}

int ans(int cnt) {
	int result = 65;
	if (cnt == C) {
		return simulation();
	}
	else {
		for (int i = 0; i < 4; i++) {
			w[cnt][2] = i;
			result = min(result, ans(cnt + 1));
		}
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j;
	cin >> N >> M;
	v.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] > 0 && v[i][j] < 6) w.push_back({ i, j, -1 });
		}
	}
	C = w.size();
	cout << ans(0);
	return 0;
}