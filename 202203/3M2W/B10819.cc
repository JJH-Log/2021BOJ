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
#define MOD 1000000007
#define BOUND 1000000000
#define MAXN 200005
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[8], w[8];
bool lock[8];
int N, res;
void backTracking(int cnt) {
	if (cnt == N) {
		int ans = 0;
		for (int i = 0; i < N - 1; i++) ans += abs(v[w[i]] - v[w[i + 1]]);
		res = max(res, ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!lock[i]) {
			lock[i] = 1;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = 0;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	res = -1e9;
	backTracking(0);
	cout << res;
	return 0;
}
