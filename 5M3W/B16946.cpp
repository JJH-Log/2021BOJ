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

vector<string> v;
vector<vector<int>> c; //c for label
map<int, int> m; //m for count
queue<pair<int, int>> q;

int N, M;

int summary(int x, int y) {
	int k, dx, dy;
	int result;
	result = 0;
	set<int> label;
	for (k = 0; k < 4; k++) {
		dx = x + "2011"[k] - '1';
		dy = y + "1120"[k] - '1';
		if (dx >= 0 && dx < N && dy >= 0 && dy < M) label.insert(c[dx][dy]);
	}
	for (auto it = label.begin(); it != label.end(); it++) result += m[*it];
	return (result + 1) % 10;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, lb, cnt;
	int x, y, dx, dy;
	cin >> N >> M;
	v.resize(N);
	c.resize(N, vector<int>(M, 0)); //cnt, lb
	for (i = 0; i < N; i++) cin >> v[i];
	lb = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (v[i][j] == '0' && !c[i][j]) {
				lb++;
				c[i][j] = lb;
				cnt = 1;
				q.push({ i,j });
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (k = 0; k < 4; k++) {
						dx = x + "2011"[k] - '1';
						dy = y + "1120"[k] - '1';
						if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
							if (v[dx][dy] == '0' && !c[dx][dy]) {
								cnt++;
								c[dx][dy] = lb;
								q.push({ dx, dy });
							}
						}
					}
				}
				m[lb] = cnt;
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (v[i][j] == '1') cout << summary(i, j);
			else cout << 0;
		}
		cout << '\n';
	}
	return 0;
}
