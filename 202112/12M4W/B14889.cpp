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

int N, v[20][20];
int w[20], uw[20];
lld result = 1e9;

void backTracking(int cnt, int ucnt, int idx) {
	if (cnt == N / 2) {
		for (int i = idx; i < N; i++) uw[ucnt++] = i;
		lld ra, ba;
		ra = ba = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				ra += v[w[i]][w[j]] + v[w[j]][w[i]];
			}
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				ba += v[uw[i]][uw[j]] + v[uw[j]][uw[i]];
			}
		}
		result = min(result, abs(ra - ba));
		return;
	}
	for (int i = idx, j = 0; i < N; i++, j++) {
		w[cnt] = i;
		backTracking(cnt + 1, ucnt + j, i + 1);
		uw[ucnt + j] = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	backTracking(0, 0, 0);
	cout << result;
	return 0;
}
