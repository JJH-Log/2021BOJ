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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
int v[1001][1001], D[1001][1001], L[1001], R[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int j = 2; j <= M; j++) D[0][j] = -1e8;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> v[i][j];
	}
	for (int i = 1; i <= N; i++) {
		L[1] = D[i - 1][1] + v[i][1];
		R[M] = D[i - 1][M] + v[i][M];
		for (int j = 2; j <= M; j++) L[j] = max(L[j - 1], D[i - 1][j]) + v[i][j];
		for (int j = M - 1; j >= 1; j--) R[j] = max(R[j + 1], D[i - 1][j]) + v[i][j];
		for (int j = 1; j <= M; j++) D[i][j] = max(L[j], R[j]);
	}
	cout << D[N][M];

	return 0;
}