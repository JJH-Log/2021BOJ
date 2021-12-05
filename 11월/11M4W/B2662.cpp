#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[21][301], dp[21][301];
int N, M;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= M; j++) {
			cin >> v[j][n];
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; j >= k; k++) dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + v[i][k]);
		}
	}
	int ridx = 0;
	for (int j = 0; j <= N; j++) if (dp[M][ridx] < dp[M][j]) ridx = j;
	cout << dp[M][ridx] << '\n';

	for (int i = M; i >= 1; i--) {
		for (int k = 0; k <= ridx; k++) {
			if (dp[i][ridx] == dp[i - 1][ridx - k] + v[i][k]) {
				s.push(k);
				ridx -= k;
				k = ridx + 1;
			}
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}
