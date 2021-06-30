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
vector<vector<int>> dp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, total, result, temp;
	cin >> N >> M;
	v.resize(N, vector<int>(2, 0));
	total = 0;
	for (i = 0; i < N; i++) cin >> v[i][0];
	for (i = 0; i < N; i++) cin >> v[i][1];
	for (i = 0; i < N; i++) total += v[i][1];
	dp.resize(N, vector<int>(total + 1, 0));
	dp[0][v[0][1]] = v[0][0];
	for (i = 1; i < N; i++) {
		if (!v[i][1]) dp[i][0] = dp[i - 1][0] + v[i][0];
		else dp[i][0] = dp[i - 1][0];
		for (j = 1; j <= total; j++) {
			if (j == v[i][1]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][0] + v[i][0]);
			else if (j > v[i][1]) {
				temp = dp[i - 1][j - v[i][1]];
				if (temp) dp[i][j] = max(dp[i - 1][j], temp + v[i][0]);
				else dp[i][j] = dp[i - 1][j];
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	result = 0;
	for (j = 0; j <= total; j++) {
		if (dp[N - 1][j] >= M) { result = j, j = total + 1; }
	}
	cout << result;

	return 0;
}
