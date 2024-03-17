#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#include <regex>
#define MOD 1000000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, K, B, X, v[100001], w[100001], res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K >> B;
	fill(v, v + N + 1, 1);
	for (int i = 0; i < B; i++) {
		cin >> X;
		v[X] = 0;
	}
	for (int i = 1; i <= N; i++) w[i] = w[i - 1] + v[i];
	for (int i = K; i <= N; i++) res = max(res, w[i] - w[i - K]);
	cout << K - res;

	return 0;
}