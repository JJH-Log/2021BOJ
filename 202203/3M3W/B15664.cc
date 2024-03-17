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
#define BOUND 1000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 2002
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, M, v[8], w[8];
bool lock[8];

void backTracking(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << v[w[i]] << ' ';
		cout << '\n';
		return;
	}
	int before = 0;
	for (int i = idx; i < N; i++) {
		if (v[i] == before) continue;
		if (!lock[i]) {
			lock[i] = true;
			w[cnt] = i;
			backTracking(i + 1, cnt + 1);
			lock[i] = false;
		}
		before = v[i];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	backTracking(0, 0);

	return 0;
}