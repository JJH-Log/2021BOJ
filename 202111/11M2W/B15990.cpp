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

int v[3][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v[0][1] = v[1][2] = v[0][3] = v[1][3] = v[2][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		v[0][i] = (v[1][i - 1] + v[2][i - 1]) % MOD;
		v[1][i] = (v[0][i - 2] + v[2][i - 2]) % MOD;
		v[2][i] = (v[0][i - 3] + v[1][i - 3]) % MOD;
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << ((lld)v[0][N] + v[1][N] + v[2][N]) % MOD << '\n';
	}


	return 0;
}
