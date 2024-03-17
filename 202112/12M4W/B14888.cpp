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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, v[11], w[11];
int op[4];
int lock[4];
lld M, m;

void backTracking(int cnt) {
	if (cnt == N) {
		lld ans = v[0];
		for (int i = 1; i < N; i++) {
			if (w[i] == 0) ans = ans + v[i];
			else if (w[i] == 1) ans = ans - v[i];
			else if (w[i] == 2) ans = ans * v[i];
			else ans = ans / v[i];
		}
		M = max(M, ans);
		m = min(m, ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (lock[i] < op[i]) {
			lock[i]++;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i]--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < 4; i++) cin >> op[i];
	M = -1e10 - 1;
	m = 1e10 + 1;
	backTracking(1);
	cout << M << '\n' << m;

	return 0;
}
