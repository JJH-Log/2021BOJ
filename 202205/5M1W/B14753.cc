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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, res, v[10000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	res = v[N - 1] * v[N - 2] * v[N - 3];
	res = max(res, v[N - 1] * v[N - 2]);
	res = max(res, v[0] * v[1]);
	res = max(res, v[0] * v[1] * v[N - 1]);
	res = max(res, v[0] * v[N - 1] * v[N - 2]);
	cout << res;

	return 0;
}