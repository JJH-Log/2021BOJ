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
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[1000];
int dp[1000];
int N, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		dp[i] = max(dp[i], v[i]);
		for (int j = i + 1; j < N; j++) {
			if (v[i] < v[j]) dp[j] = max(dp[j], dp[i] + v[j]);
		}
		res = max(dp[i], res);
	}
	cout << res;


	return 0;
}
