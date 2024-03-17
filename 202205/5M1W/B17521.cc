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

int N, v[15];
lld W, C;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> v[i];
	if (N == 1) {
		cout << W;
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		if (C) {
			W += C * v[i];
			C = 0;
		}
		if (v[i] < v[i + 1]) {
			C += W / v[i];
			W -= C * v[i];
		}
	}
	if (C) W += C * v[N - 1];
	cout << W;
	
	return 0;
}
