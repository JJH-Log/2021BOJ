#define _CRT_SECURE_NO_WARNINGS
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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int N;
string s;
int dp[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, a, b, x, y;
	cin >> N >> s;
	dp[0] = dp[1] = 0;
	for (i = 0; i < N; i++) {
		if (s[i] == 'A') a = 1, b = 0;
		else a = 0, b = 1;
		x = min(dp[0] + b, dp[1] + 1);
		y = min(dp[1] + a, dp[0] + 1);
		dp[0] = x, dp[1] = y;
	}
	cout << min(dp[0], dp[1] + 1);

	
	return 0;
}