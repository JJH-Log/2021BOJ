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
#define INT_MIN -2147483647
#define INT_MAX 2147483647
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<lld>> v;
vector<vector<pair<lld, lld>>> dp;

int N;

lld calculate(lld x, lld oper, lld y) {
	if (oper == '+' - '0') return x + y;
	if (oper == '-' - '0') return x - y;
	if (oper == '*' - '0') return x * y;
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int i, j, k, num;
	string s;
	num = (N + 1) / 2;
	v.resize(2, vector<lld>(num, 0));
	dp.resize(num, vector<pair<lld, lld>>(num, { INT_MIN, INT_MAX }));
	cin >> s;
	for (i = 0; i < N; i++) v[i % 2][i / 2] = s[i] - '0';
	for (i = 0; i < num; i++) dp[i][i] = { v[0][i], v[0][i] };
	for (j = 0; j < num; j++) {
		for (i = 0; i + j < num; i++) {
			for (k = i; k < i + j; k++) {
				dp[i][i + j].first = max(dp[i][i + j].first, calculate(dp[i][k].first, v[1][k], dp[k + 1][i + j].first));
				dp[i][i + j].first = max(dp[i][i + j].first, calculate(dp[i][k].first, v[1][k], dp[k + 1][i + j].second));
				dp[i][i + j].first = max(dp[i][i + j].first, calculate(dp[i][k].second, v[1][k], dp[k + 1][i + j].first));
				dp[i][i + j].first = max(dp[i][i + j].first, calculate(dp[i][k].second, v[1][k], dp[k + 1][i + j].second));
				dp[i][i + j].second = min(dp[i][i + j].second, calculate(dp[i][k].first, v[1][k], dp[k + 1][i + j].first));
				dp[i][i + j].second = min(dp[i][i + j].second, calculate(dp[i][k].first, v[1][k], dp[k + 1][i + j].second));
				dp[i][i + j].second = min(dp[i][i + j].second, calculate(dp[i][k].second, v[1][k], dp[k + 1][i + j].first));
				dp[i][i + j].second = min(dp[i][i + j].second, calculate(dp[i][k].second, v[1][k], dp[k + 1][i + j].second));
			}
		}
	}
	
	cout << dp[0][num - 1].first;

	return 0;
}