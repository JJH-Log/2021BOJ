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
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, n, m, R, v[100][100], w[100][100];

void op1() {
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N - 1 - i; i++) swap(v[i][j], v[N - 1 - i][j]);
	}
}

void op2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1 - j; j++) swap(v[i][j], v[i][M - 1 - j]);
	}
}

void _copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) v[i][j] = w[i][j];
	}
}

void op3() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) w[j][N - 1 - i] = v[i][j];
	}
	swap(N, M); swap(n, m);
	_copy();
}

void op4() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) w[M - 1 - j][i] = v[i][j];
	}
	swap(N, M); swap(n, m);
	_copy();
}

void op5() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i < n) {
				if (j < m) w[i][j + m] = v[i][j];
				else w[i + n][j] = v[i][j];
			}
			else {
				if (j < m) w[i - n][j] = v[i][j];
				else w[i][j - m] = v[i][j];
			}
		}
	}
	_copy();
}


void op6() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i < n) {
				if (j < m) w[i + n][j] = v[i][j];
				else w[i][j - m] = v[i][j];
			}
			else {
				if (j < m) w[i][j + m] = v[i][j];
				else w[i - n][j] = v[i][j];
			}
		}
	}
	_copy();
}



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;
	n = N / 2, m = M / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}

	int q;
	for (int i = 0; i < R; i++) {
		cin >> q;
		if (q == 1) op1();
		if (q == 2) op2();
		if (q == 3) op3();
		if (q == 4) op4();
		if (q == 5) op5();
		if (q == 6) op6();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cout << v[i][j] << ' ';
		cout << '\n';
	}


	return 0;
}