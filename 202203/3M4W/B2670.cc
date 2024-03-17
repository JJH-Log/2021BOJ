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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

double res, v[10000];
int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(3);
	cout << fixed;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 1; i < N; i++) {
		if (v[i - 1] >= 1) v[i] *= v[i - 1];
		res = max(res, v[i]);
	}
	cout << res;

	return 0;
}