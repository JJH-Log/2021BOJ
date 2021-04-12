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



vector<vector<vector<int>>> v;
vector<vector<int>> fv;
vector<vector<int>> nv;
vector<vector<int>> dv;
vector<vector<int>> wv;

void spread_tree(int x, int y, int t, int N) {
	int dx[3] = { -1, 0, 1 };
	int dy[3] = { -1, 0, 1 };
	int nx, ny, k;
	for (k = 0; k < 9; k++) {
		if (k != 4) {
			nx = x + dx[k / 3];
			ny = y + dy[k % 3];
			if ((nx >= 0) && (nx <= N - 1) && (ny >= 0) && (ny <= N - 1)) fv[nx][ny] += v[x][y][t];
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, N, M, K, T;
	int x, y, t;
	cin >> N >> M >> K;

	v.resize(N, vector<vector<int>>(N, vector<int>(1012, 0)));
	wv.resize(N, vector<int>(N, 0)); //겨울 : 비료
	nv.resize(N, vector<int>(N, 5)); //현재 양분
	dv.resize(N, vector<int>(N, 0)); //죽은 나무 양분
	fv.resize(N, vector<int>(N, 0)); //새로 태어난 나무 개수
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> wv[i][j];
		}
	}
	for (i = 0; i < M; i++) {
		cin >> x >> y >> t;
		v[x - 1][y - 1][t]++;
		v[x - 1][y - 1][0] = max(v[x - 1][y - 1][0], t);
	}


	int last_tsd;

	for (T = 0; T < K; T++) {
		//need fv, dv reset 
		for (auto& sub : dv) std::fill(sub.begin(), sub.end(), 0);
		for (auto& sub : fv) std::fill(sub.begin(), sub.end(), 0);
		//spring starts
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (v[i][j][0] != 0) {
					last_tsd = 0;
					for (t = 1; t <= v[i][j][0]; t++) {
						if (v[i][j][t] != 0) {
							if (nv[i][j] >= t * v[i][j][t]) nv[i][j] -= t * v[i][j][t];
							else {
								dv[i][j] += (v[i][j][t] - (nv[i][j] / t)) * (t / 2);
								v[i][j][t] = nv[i][j] / t;
								nv[i][j] %= t;
							}
							if (v[i][j][t] != 0) {
								last_tsd = t;
								if (t % 5 == 4) spread_tree(i, j, t, N);
							}
						}
					}
					v[i][j][0] = last_tsd;
				}
			}
		}

		//summer & fall & winter starts
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				nv[i][j] += dv[i][j];

				if (v[i][j][0] != 0) {
					for (t = v[i][j][0]; t >= 1; t--) v[i][j][t + 1] = v[i][j][t];
					v[i][j][0]++;
				}
				if (fv[i][j] == 0) v[i][j][1] = 0;
				else {
					v[i][j][1] = fv[i][j];
					if (v[i][j][0] == 0) v[i][j][0] = 1;
				}

				nv[i][j] += wv[i][j];
			}
		}

	}

	int result = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (t = 1; t <= v[i][j][0]; t++) result += v[i][j][t];
		}
	}

	cout << result;


	return 0;
}
