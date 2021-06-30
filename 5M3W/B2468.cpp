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


vector<vector<int>> v;
vector<vector<int>> w;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, h, N, cnt, result;
	int t, tx, ty;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	result = 1;
	for (i = 0; i < N * N; i++) cin >> v[i / N][i % N];
	for (h = 1; h < 100; h++) {
		w.clear();
		w.resize(N, vector<int>(N, 0));
		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (v[i][j] > h && !w[i][j]) {
					cnt++;
					w[i][j] = 1;
					q.push({ i,j });
					while (!q.empty()) {
						tx = q.front().first;
						ty = q.front().second;
						q.pop();
						for (t = 0; t < 4; t++) {
							int dx = tx + "2011"[t] - '1';
							int dy = ty + "1120"[t] - '1';
							if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
								if (v[dx][dy] > h && !w[dx][dy]) {
									w[dx][dy] = 1;
									q.push({ dx, dy });
								}
							}
						}
					}
				}
			}
		}
		result = max(result, cnt);
		if (!cnt) h = 100;
	}
	cout << result;
	return 0;
}