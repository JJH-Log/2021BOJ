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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, D, K, C;
int v[30000];
int cnt[3001], total, res;

void add(int d) {
	if (!cnt[d]) total++;
	cnt[d]++;
}

void sub(int d) {
	cnt[d]--;
	if (!cnt[d]) total--;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++) cin >> v[i];

	add(C);
	for (int i = 0; i < K; i++) add(v[i]);
	res = total;
	for (int i = 0; i < N; i++) {
		add(v[(i + K) % N]);
		sub(v[i]);
		res = max(res, total);
	}
	cout << res;

	return 0;
}