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

lld T, N, M;
lld v[1000000];
lld res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> v[i];
		M = res = 0;
		for (int i = N - 1; i >= 0; i--) {
			M = max(M, v[i]);
			res += M - v[i];
		}
		cout << res << '\n';
	}

	return 0;
}