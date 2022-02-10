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

vector<int> v;
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, K;
	cin >> N >> K;
	v.resize(N, 0);
	dp.resize(K + 1, 10001);
	for (i = 0; i < N; i++) cin >> v[i];
	dp[0] = 0;
	for (i = 0; i <= K; i++) {
		for (j = 0; j < N; j++) {
			if (i + v[j] <= K) dp[i + v[j]] = min(dp[i + v[j]], dp[i] + 1);
		}
	}
	if (dp[K] == 10001) cout << -1;
	else cout << dp[K];
	return 0;
}