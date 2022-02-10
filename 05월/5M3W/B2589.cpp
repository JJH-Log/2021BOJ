#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;


vector<string> v;
vector<vector<int>> w;
queue<pair<int, int>> q;
int N, M;
int ans(int x, int y) {
	int i = 0;
	int tx, ty;
	int result = 0;
	w.clear();
	w.resize(N, vector<int>(M, -1));
	w[x][y] = 0;
	q.push({ x,y, });
	while (!q.empty()) {
		tx = q.front().first;
		ty = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int dx = tx + "2011"[i] - '1';
			int dy = ty + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
				if (v[dx][dy] == 'L' && w[dx][dy] == -1) {
					w[dx][dy] = w[tx][ty] + 1;
					result = w[dx][dy];
					q.push({ dx, dy });
				}
			}
		}
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, result;
	cin >> N >> M;
	v.resize(N);
	result = 0;
	for (i = 0; i < N; i++) cin >> v[i];
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if(v[i][j] == 'L') result = max(result, ans(i, j));
		}
	}
	cout << result;
	return 0;
}