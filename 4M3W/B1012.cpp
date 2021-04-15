#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

vector<vector<int>> v;

void combine(int x, int y, int N, int M) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int i;
	int nx, ny;
	v[x][y] = 0;
	for (i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if ((nx != -1) && (ny != -1) && (nx != N) && (ny != M)) {
			if (v[nx][ny] == 1) combine(nx, ny, N, M);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, T, t, N, M, K;
	int x, y, result;
	cin >> T;

	for (t = 0; t < T; t++) {
		cin >> M >> N >> K;
		v.clear();
		v.resize(N, vector<int>(M, 0));
		result = 0;
		for (i = 0; i < K; i++) { cin >> y >> x; v[x][y]++; }
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (v[i][j] == 1) {
					result++;
					combine(i, j, N, M);
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}
