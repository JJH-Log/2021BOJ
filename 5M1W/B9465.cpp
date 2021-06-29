#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, T, N;
	cin >> T;
	for (t = 0; t < T; t++) {
		v.clear();
		dp.clear();
		cin >> N;
		v.resize(2, vector<int>(N, 0));
		dp.resize(2, vector<int>(N, 0));
		for (i = 0; i < N; i++) cin >> v[0][i];
		for (i = 0; i < N; i++) cin >> v[1][i];
		if (N == 1) cout << max(v[0][0], v[0][1]) << "\n";
		else {
			dp[0][0] = v[0][0];
			dp[1][0] = v[1][0];
			dp[1][1] = v[0][0] + v[1][1];
			dp[0][1] = v[1][0] + v[0][1];
			for (i = 2; i < N; i++) {
				dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
				dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
			}
			cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
		}

	}
}