#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;
vector<vector<int>> a; //after

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, T;
	int i, j, k, t;
	int p, cnt, vi, vj;
	int result;
	cin >> N >> M >> T;
	v.resize(N + 2, vector<int>(M + 2, -1));
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> v[i][j];
			if (v[i][j] == -1) p = i;
		}
	}

	for (t = 0; t < T; t++) {
		a.clear();
		a.resize(N + 2, vector<int>(M + 2, 0));
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				if (v[i][j] != -1) {
					cnt = 0;
					for (k = 0; k < 4; k++) {
						vi = i + "1120"[k] - '1';
						vj = j + "2011"[k] - '1';
						if (v[vi][vj] != -1) a[vi][vj] += (v[i][j] / 5), cnt++;
					}
					a[i][j] += v[i][j] - (v[i][j] / 5) * cnt;
				}
			}
		}

		for (i = p + 1; i < N; i++) a[i][1] = a[i + 1][1];
		for (i = p - 2; i > 1; i--) a[i][1] = a[i - 1][1];
		for (j = 1; j < M; j++) a[1][j] = a[1][j + 1], a[N][j] = a[N][j + 1];

		for (i = N; i > p; i--) a[i][M] = a[i - 1][M];
		for (i = 1; i < p - 1; i++) a[i][M] = a[i + 1][M];
		for (j = M; j > 1; j--) a[p][j] = a[p][j - 1], a[p - 1][j] = a[p - 1][j - 1];
		a[p][2] = 0, a[p - 1][2] = 0;

		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				if (v[i][j] != -1) v[i][j] = a[i][j];
			}
		}
	}

	result = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (v[i][j] != -1) result += v[i][j];
		}
	}
	cout << result;
	return 0;
}