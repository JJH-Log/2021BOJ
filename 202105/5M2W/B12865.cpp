#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<pair<int, int>> v;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, i, j, x, y, result;
	cin >> N >> K;

	for (i = 0; i < N; i++) {
		cin >> x >> y;
		if (y) v.push_back({ x, y });
	}
	dp.resize(v.size(), vector<int>(K + 1, 0));
	for (i = 0; i < v.size(); i++) {
		for (j = 0; j <= K; j++) {
			if (j < v[i].first) {
				if(i) dp[i][j] = dp[i - 1][j];
			}
			else {
				if (i) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
				else dp[i][j] = v[i].second;
			}
		}
	}
	cout << dp[v.size() - 1][K];
	return 0;
}