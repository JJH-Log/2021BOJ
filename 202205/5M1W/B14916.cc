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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, v[100010];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fill(v, v + 100010, 1e9);
	v[0] = 0;
	for (int i = 0; i <= 100000; i++) {
		v[i + 2] = min(v[i + 2], v[i] + 1);
		v[i + 5] = min(v[i + 5], v[i] + 1);
	}
	cin >> N;
	if (v[N] == 1e9) cout << -1;
	else cout << v[N];

	
	return 0;
}
