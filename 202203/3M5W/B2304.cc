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
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[1001], l[1001], r[1001];


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v[x] = y;
	}
	l[1] = v[1]; r[1000] = v[1000];
	for (int i = 1; i <= 1000; i++) l[i] = max(v[i], l[i - 1]);
	for (int i = 999; i >= 1; i--) r[i] = max(v[i], r[i + 1]);

	int total = 0;
	for (int i = 1; i <= 1000; i++) total += min(l[i], r[i]);
	cout << total;
	
	return 0;
}