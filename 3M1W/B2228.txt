#include <iostream>
#include <vector>
using namespace std;


vector<int> ar;
vector<vector<int>> dp;
vector<vector<bool>> visit;
#define MIN -3276900;


int ans(int n, int m) {
	if (m == 0) return 0;
	if (n < 2 * m - 1) return MIN;
	if (visit[n][m]) return dp[n][m];

	int i, sum, temp, A, B;
	A = ans(n - 1, m);
	B = MIN;
	sum = 0;
	for (i = n; i > 0; i--) {
		sum += ar[i];
		temp = ans(i - 2, m - 1) + sum;
		if (B < temp) {
			B = temp;
		}
	}
	dp[n][m] = max(A, B);
	visit[n][m] = true;
	return dp[n][m];
}

int main() {
	int i,N, M;
	cin >> N >> M;
	
	ar.resize(N+1);
	dp.resize(N+1, vector<int>(M+1, 0));
	visit.resize(N + 1, vector<bool>(M + 1, false));

	for (i = 1; i <= N; i++) {
		cin >> ar[i];
	}

	cout << ans(N,M) << "\n";
}