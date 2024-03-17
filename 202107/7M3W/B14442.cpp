#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
#define INT_MIN -2147483647
#define INT_MAX 2147483647
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<vector<int>>> w;
queue<vector<int>> q;
int N, M, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	v.resize(N, vector<int>(M, 0));
	w.resize(K + 1, vector<vector<int>>(N, vector<int>(M, 1e9)));

	int i, j;
	string s;
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++) v[i][j] = s[j] - '0';
	}
	
	w[0][0][0] = 1;
	q.push({ 0, 0, 0 });
	int x, y, f, dx, dy, df;
	while (!q.empty()) {
		f = q.front()[0];
		x = q.front()[1];
		y = q.front()[2];
		q.pop();
		for (i = 0; i < 4; i++) {
			dx = x + "2011"[i] - '1';
			dy = y + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && f + v[dx][dy] <= K) {
				df = f + v[dx][dy];
				if (w[df][dx][dy] == 1e9) w[df][dx][dy] = w[f][x][y] + 1, q.push({ df, dx, dy });
			}
		}
	}
	int result = 1e9;
	for (i = 0; i <= K; i++) result = min(result, w[i][N - 1][M - 1]);
	if (result == 1e9) cout << -1;
	else cout << result;

	return 0;
}