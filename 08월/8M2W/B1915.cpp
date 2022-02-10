#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<vector<int>>> dp; //0: 세로축, 1: 가로축, 2: 대각선 포함 전체
int N, M;


int trimin(int a, int b, int c) {
	return min(min(a, b), c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int i, j;
	cin >> N >> M;
	v.resize(N, vector<int>(M, 0));
	dp.resize(N, vector<vector<int>>(M, vector<int>(3, 0)));
	int result = 0;
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++) {
			v[i][j] = s[j] - '0';
			if (v[i][j]) {
				if (!i) dp[i][j][0] = 1;
				else dp[i][j][0] = dp[i - 1][j][0] + 1;

				if (!j) dp[i][j][1] = 1;
				else dp[i][j][1] = dp[i][j - 1][1] + 1;

				if (!i || !j) dp[i][j][2] = 1;
				else dp[i][j][2] = trimin(dp[i - 1][j][0], dp[i][j - 1][1], dp[i - 1][j - 1][2]) + 1;

				result = max(result, dp[i][j][2]);
			}
		}
	}
	cout << result * result;
	return 0;
}