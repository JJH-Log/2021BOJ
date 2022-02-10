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

lld N, M, M2, R5, R2, R, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld t;
	cin >> N >> M;
	
	M = max(M, N - M);
	M2 = N - M;
	for (t = 5; t <= N; t *= 5) R5 += (N / t) - (M / t);
	for (t = 5; t <= M2; t *= 5) R5 -= (M2 / t);
	for (t = 2; t <= N; t *= 2) R2 += (N / t) - (M / t);
	for (t = 2; t <= M2; t *= 2) R2 -= (M2 / t);
	R = min(R5, R2);
	cout << max((lld)0, R);

	return 0;
}
