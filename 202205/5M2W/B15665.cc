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

int N, M, x;
int v[7], w[7];
set<int> S;

void backTracking(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << v[w[i]] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		w[cnt] = i;
		backTracking(cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		S.insert(x);
	}
	N = S.size();
	int cnt = 0;
	for (auto t : S) v[cnt++] = t;
	backTracking(0);

	return 0;
}