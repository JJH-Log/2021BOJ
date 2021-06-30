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

vector<int> v;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j, N, M, x, y, temp;
	cin >> N;
	v.resize(N, 0);
	dp.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) cin >> v[i];
	for (j = 0; j < N; j++) {
		for (i = 0; i + j < N; i++) {
			if (j == 0) dp[i][i + j] = 1;
			else if (j == 1) { if (v[i] == v[i + 1]) dp[i][i + j] = 1; }
			else if (dp[i + 1][i + j - 1] == 1 && v[i] == v[i + j]) dp[i][i + j] = 1;
		}
	}

	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		cout << dp[x - 1][y - 1] << '\n';
	}
	return 0;
}
