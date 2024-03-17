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

vector<vector<int>> dp;

int cost(int X, int Y) {
	if (!X) return 2;
	if (X == Y) return 1;
	return 4 - ((X + Y) % 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, B, temp, result, tx, ty;
	vector<int> vx, vy;

	dp.resize(5, vector<int>(5, (int)1e9));
	vx.resize(5);
	vy.resize(5);
	dp[0][0] = 0; B = 0;
	while (true) {
		cin >> N;
		if (!N) break;
		if (!dp[0][0]) {
			dp[0][0] = (int)1e9;
			dp[N][0] = 2;
			dp[0][N] = 2;
		}
		else {
			temp = (int)1e9;
			tx = (int)1e9;
			ty = (int)1e9;
			for (i = 0; i < 5; i++) {
				if (i != B) {
					vx[i] = dp[B][i] + cost(B, N);
					vy[i] = dp[i][B] + cost(B, N);
				}
				tx = min(tx, dp[i][B] + cost(i, N));
				ty = min(ty, dp[B][i] + cost(i, N));
			}
			vx[B] = tx, vy[B] = ty, vx[N] = min(vx[N], vy[N]), vy[N] = vx[N];
			for (i = 0; i < 5; i++) {
				dp[i][N] = vx[i];
				dp[N][i] = vy[i];
			}
		}
		B = N;
	}
	result = (int)1e9;
	for (i = 0; i < 5; i++) {
		result = min(result, dp[B][i]);
		result = min(result, dp[i][B]);
	}
	cout << result;
	return 0;
}
