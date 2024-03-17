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

lld N, v[11], w[10], op[4];
lld resM, resm;

lld operation(lld x, lld y, int op) {
	if (op == 0) return x + y;
	if (op == 1) return x - y;
	if (op == 2) return x * y;
	if (op == 3) return x / y;
}

void backTracking(int cnt) {
	if (cnt == N - 1) {
		lld ans = v[0];
		for (int i = 0; i < N - 1; i++) ans = operation(ans, v[i + 1], w[i]);
		resM = max(resM, ans);
		resm = min(resm, ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i]--;
			w[cnt] = i;
			backTracking(cnt + 1);
			op[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < 4; i++) cin >> op[i];
	resM = -(lld)2e9 - 1; resm = (lld)2e9 + 1;
	backTracking(0);
	cout << resM << '\n' << resm;

	return 0;
}