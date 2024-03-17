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

int v[10], w[10], N;
bool lock[10], FLAG;

void backTracking(int cnt) {
	if (FLAG) return;
	if (cnt == N) {
		int ans[10] = { 0, };
		for (int i = 0; i < N; i++) ans[i] = w[i] + 1;

		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < i; j++) if (ans[j] > ans[i]) cnt++;
			if (cnt != v[w[i]]) return;
		}

		for (int i = 0; i < N; i++) cout << ans[i] << ' ';
		FLAG = true;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!lock[i]) {
			lock[i] = true;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	backTracking(0);

	return 0;
}