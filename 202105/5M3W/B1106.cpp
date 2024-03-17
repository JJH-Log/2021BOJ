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
vector<int> dp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, M, N, temp, result;
	cin >> M >> N;
	dp.resize(M + 110, 1e9);
	v.resize(N, vector<int>(2, 0));
	dp[0] = 0;
	for (i = 0; i < N; i++) cin >> v[i][0] >> v[i][1];
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			temp = i + v[j][1];
			dp[temp] = min(dp[temp], dp[i] + v[j][0]);
		}
	}
	result = 1e9;
	for (i = M; i < M + 110; i++) result = min(result, dp[i]);
	cout << result;
	return 0;
}