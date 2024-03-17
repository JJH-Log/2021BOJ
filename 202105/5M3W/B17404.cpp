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
vector<vector<int>> dp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, result = 1e9;
	cin >> N;
	v.resize(N, vector<int>(3, 0));
	dp.resize(N, vector<int>(9, 0));
	for (i = 0; i < N; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];
	
	dp[0][0] = v[0][0];
	dp[0][4] = v[0][1];
	dp[0][8] = v[0][2];
	dp[0][1] = dp[0][2] = dp[0][3] = dp[0][5] = dp[0][6] = dp[0][7] = 30000;
	for (i = 1; i < N; i++) {
		for (j = 0; j < 3; j++) {
			dp[i][j * 3] = v[i][0] + min(dp[i - 1][j * 3 + 1], dp[i - 1][j * 3 + 2]);
			dp[i][j * 3 + 1] = v[i][1] + min(dp[i - 1][j * 3], dp[i - 1][j * 3 + 2]);
			dp[i][j * 3 + 2] = v[i][2] + min(dp[i - 1][j * 3 + 1], dp[i - 1][j * 3]);
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (i != j) result = min(result, dp[N - 1][3 * i + j]);
		}
	}
	cout << result;
	return 0;
}