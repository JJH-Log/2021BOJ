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
vector<vector<int>> ans;
vector<int> t;

void bfs(int x, int y, int unique) {
	if ((v[x + 1][y] == v[x][y]) && (ans[x + 1][y] == -1)) { ans[x + 1][y] = unique; bfs(x + 1, y, unique); }
	if ((v[x - 1][y] == v[x][y]) && (ans[x - 1][y] == -1)) { ans[x - 1][y] = unique; bfs(x - 1, y, unique); }
	if ((v[x][y + 1] == v[x][y]) && (ans[x][y + 1] == -1)) { ans[x][y + 1] = unique; bfs(x, y + 1, unique); }
	if ((v[x][y - 1] == v[x][y]) && (ans[x][y - 1] == -1)) { ans[x][y - 1] = unique; bfs(x, y - 1, unique); }
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, temp, unique;
	string s;
	cin >> N;

	v.resize(N + 2, vector<int>(N + 2, 0));
	ans.resize(N + 2, vector<int>(N + 2, -1));

	for (i = 1; i <= N; i++) {
		cin >> s;
		for (j = 0; j < s.size(); j++) {
			if (s[j] == 'R') v[i][j + 1] = 1;
			if (s[j] == 'G') v[i][j + 1] = 2;
			if (s[j] == 'B') v[i][j + 1] = 3;
		}
	}

	unique = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j ++) {
			if (ans[i][j] == -1) {
				bfs(i, j, unique);
				unique++;
			}
		}
	}
	cout << unique << " ";

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (v[i][j] == 1) v[i][j] = 2;
		}
	}
	ans.clear();
	ans.resize(N + 2, vector<int>(N + 2, -1));
	unique = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (ans[i][j] == -1) {
				bfs(i, j, unique);
				unique++;
			}
		}
	}
	cout << unique;

	return 0;
}
