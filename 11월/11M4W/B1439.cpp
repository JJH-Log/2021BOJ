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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, M, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	int x;
	for (int i = 0; i < N; i++) cin >> x;
	for (int i = 0; i < K; i++) {
		cin >> x;
		if (x > 0 && M <= x) M = x + 1 - M;
		if (x < 0 && M > (N + x)) M = 2 * N + x + 1 - M;
	}
	cout << M;

	return 0;
}
