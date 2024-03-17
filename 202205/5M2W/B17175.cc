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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, v[51];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	v[0] = v[1] = 1;
	for (int i = 2; i <= 50; i++) v[i] = (v[i - 1] + v[i - 2] + 1) % MOD;
	cin >> N;
	cout << v[N];

	return 0;
}