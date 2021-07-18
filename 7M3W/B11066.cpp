#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> file;
vector<vector<int>> dp; // i , j : i부터 j + 1개만큼을 합침
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, t, T;
	int result;

	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		dp.resize(N, vector<int>(N, 0));
		file.resize(N, vector<int>(N, 0));
		for (i = 0; i < N; i++) cin >> file[i][0];

		for (j = 1; j < N; j++) {
			for (i = 0; i + j < N; i++) {
				file[i][j] = file[i][j - 1] + file[i + j][0];
			}
		}

		for (j = 1; j < N; j++) {
			for (i = 0; i + j < N; i++) {
				for (k = 0; k < j; k++) {
					result = dp[i][k] + dp[i + k + 1][j - (k + 1)] + file[i][j];
					if (k == 0) dp[i][j] = result;
					else dp[i][j] = min(dp[i][j], result);
				}
			}
		}
		cout << dp[0][N - 1] << '\n';
		dp.clear();
		file.clear();
	}

	return 0;
}