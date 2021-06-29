#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int x, y, i, j, N, M;
	cin >> N >> M;
	v.resize(N + 2, vector<int>(M + 2, -1));
	for (i = 1; i <= N; i++) {
		cin >> s;
		for (j = 1; j <= M; j++) v[i][j] = s[j - 1] - '0';
	}
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 4; i++) {
			x = temp.first + ("2011"[i] - '1');
			y = temp.second + ("1120"[i] - '1');
			if (v[x][y] == 1) {
				v[x][y] = v[temp.first][temp.second] + 1;
				q.push(make_pair(x, y));
			}
		}
	}
	cout << v[N][M];
}

