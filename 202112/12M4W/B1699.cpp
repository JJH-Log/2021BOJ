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

vector<int> v;
int N, dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(dp, dp + 100001, 10000);
	for (int i = 1; i * i <= 100000; i++) {
		dp[i * i] = 1;
		v.push_back(i * i);
	}
	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < v.size() && (i + v[j] <= 100000); j++) dp[i + v[j]] = min(dp[i + v[j]], dp[i] + 1);
	}

	cin >> N;
	cout << dp[N];


	return 0;
}
