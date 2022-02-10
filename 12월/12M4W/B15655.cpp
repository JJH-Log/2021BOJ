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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


int w[8], v[8];
int M, N;

void backTracking(int cnt, int idx) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) cout << w[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i < M; i++) {
		w[cnt] = v[i];
		backTracking(cnt + 1, i + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < M; i++) cin >> v[i];
	sort(v, v + M);
	backTracking(0, 0);

	return 0;
}
