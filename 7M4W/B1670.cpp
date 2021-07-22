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
#define MOD 987654321
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> dp; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N;
	cin >> N;
	N /= 2;
	dp.resize(N + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= N; i++) {
		//비효율적인 연산 제거 (나누기 2)
		if (i % 2) dp[i] = (dp[i] + (lld)dp[i / 2] * dp[i / 2]) % MOD;
		for (j = 0; j < i / 2; j++) dp[i] = (dp[i] + (lld)2 * dp[j] * dp[i - 1 - j]) % MOD;
	}
	cout << dp[N];
	return 0;
}