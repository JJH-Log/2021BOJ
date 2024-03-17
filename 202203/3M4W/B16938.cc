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
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, L, R, X, res;
int v[15];
void backTracking(int idx, int total, int M, int m) {
	if (idx == N) {
		if (total >= L && total <= R && (M - m) >= X) res++;
		return;
	}
	backTracking(idx + 1, total + v[idx], max(M, v[idx]), min(m, v[idx]));
	backTracking(idx + 1, total, M, m);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) cin >> v[i];
	backTracking(0, 0, 0, 1e7);
	cout << res;
	
	return 0;
}