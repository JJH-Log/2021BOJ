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
using lld = long long;

vector<int> v;
vector<vector<int>> dp;
lld B, C;

lld chain(int a, int b, int c) {
	return ((B + 2 * C) * c + (B + C) * (b - c) + B * (a - b));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N;
	lld result;
	cin >> N >> B >> C;
	v.resize(N, 0);
	dp.resize(N + 2, vector<int>(3, 0));
	for (i = 0; i < N; i++) cin >> v[i];
	result = 0;
	if (B <= C) {
		for (i = 0; i < N; i++) result += v[i];
		result *= B;
	}
	else {
		dp[0][0] = v[0];
		for (i = 1; i < N; i++) {
			dp[i][1] = min(dp[i - 1][0], v[i]);
			v[i] -= min(dp[i - 1][0], v[i]);
			dp[i][2] = min(dp[i - 1][1], v[i]);
			v[i] -= min(dp[i - 1][1], v[i]);
			dp[i][0] = v[i];
		}
		for (i = 2; i < N + 2; i++) result += chain(dp[i - 2][0], dp[i - 1][1], dp[i][2]);
	}
	cout << result;

	return 0;
}