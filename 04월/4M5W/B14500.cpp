#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;

int ans(int bx, int by, int x, int y, int cnt, int total) {
	int i, dx, dy, result;
	result = 0;
	total += v[x][y];
	cnt++;
	if (cnt == 4) return total;
	else {
		for (i = 0; i < 4; i++) {
			dx = x + "2011"[i] - '1';
			dy = y + "1120"[i] - '1';
			if(v[dx][dy] != -1 && ((dx != bx) || (dy != by))) result = max(result, ans(x, y, dx, dy, cnt, total));
		}
	}
	return result;
}

int tblock(int x, int y) {
	int i, dx, dy, result, total;
	result = 0, total = v[x][y];
	for (i = 0; i < 4; i++) total += v[x + "2011"[i] - '1'][y + "1120"[i] - '1'];
	for (i = 0; i < 4; i++) result = max(result, total - v[x + "2011"[i] - '1'][y + "1120"[i] - '1']);
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, result;
	cin >> N >> M;
	v.resize(N + 2, vector<int>(M + 2, -1));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) cin >> v[i][j];
	}
	result = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) result = max(result, ans(0, 0, i, j, 0, 0));
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) result = max(result, tblock(i, j));
	}
	cout << result;
	return 0;
}