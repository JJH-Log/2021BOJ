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

int N, K, v[100];
lld dp1[10001];
lld dp2[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);

	for (int i = 1; i <= K; i++) if (i % v[0] == 0) dp1[i] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			dp2[j] = dp1[j];
			if (j % v[i] == 0) dp2[j]++;
			for (int k = 1; j - v[i] * k > 0; k++) dp2[j] += dp1[j - v[i] * k];
		}
		swap(dp1, dp2);
		fill(dp2, dp2 + 10001, 0);
	}
	cout << dp1[K];
	
	return 0;
}
