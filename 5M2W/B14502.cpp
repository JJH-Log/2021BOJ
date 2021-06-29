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
int N, M;
int get_result() {
	vector<vector<int>> t = v;
	queue<pair<int, int>> q;
	int i, j, result;
	int dx, dy;
	result = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (t[i][j] == 2) q.push({ i,j });
		}
	}
	while (!q.empty()) {
		for (i = 0; i < 4; i++) {
			dx = q.front().first + "2011"[i] - '1';
			dy = q.front().second + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
				if (!t[dx][dy]) t[dx][dy]=1, q.push({ dx, dy });
			}
		}
		q.pop();
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (t[i][j] == 0) result++;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, result;
	cin >> N >> M;
	v.resize(N, vector<int>(M, -1));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}
	result = 0;
	for (i = 0; i < N * M; i++) {
		if (!v[i / M][i % M]) {
			v[i / M][i % M] = 1;
			for (j = i + 1; j < N * M; j++) {
				if (!v[j / M][j % M]) {
					v[j / M][j % M] = 1;
					for (k = j + 1; k < N * M; k++) {
						if (!v[k / M][k % M]) {
							v[k / M][k % M] = 1;
							result = max(result, get_result());
							v[k / M][k % M] = 0;
						}
					}
					v[j / M][j % M] = 0;
				}
			}
			v[i / M][i % M] = 0;
		}

	}
	cout << result;
	return 0;
}