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

vector<int> v;
vector<vector<long long>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, s, N;
	long long total, result;
	cin >> N;
	v.resize(N + 1, 0);
	dp.resize(N + 1, vector<long long>(N + 1, 4e10));

	for (i = 0; i < N; i++) cin >> v[i] >> v[i + 1];
	if (N == 1) {
		cout << 0;
		return 0;
	}

	for (s = 1; s <= N; s++) {
		for (i = 0; i + s <= N; i++) {
			if (s == 1) dp[i][s + i] = 0;
			else if (s == 2) dp[i][s + i] = (long long)v[i] * v[i + 1] * v[i + 2];
			else {
				for (j = i + 1; j < s + i; j++) {
					dp[i][s + i] = min(dp[i][s + i], dp[i][j] + dp[j][s + i] + (long long)v[i] * v[j] * v[s + i]);
				}
			}
		}
	}

	cout << dp[0][N];
	return 0;
}