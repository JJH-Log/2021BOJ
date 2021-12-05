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
#include <sstream>
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v[1][1] = v[1][2] = v[1][3] = 1;
	v[2][2] = v[3][3] = 1;
	v[2][3] = 2;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 4; j <= 1000; j++) {
			v[i][j] = ((lld)v[i - 1][j - 1] + v[i - 1][j - 2] + v[i - 1][j - 3]) % MOD;
		}
	}
	for (int j = 1; j <= 1000; j++) {
		for (int i = 2; i <= 1000; i++) {
			v[i][j] = (v[i][j] + v[i - 1][j]) % MOD;
		}
	}
	int N, M, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << v[M][N] << '\n';
	}


	return 0;
}
