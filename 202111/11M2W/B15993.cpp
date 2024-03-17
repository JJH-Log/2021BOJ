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

int v[100004][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v[1][1] = v[2][1] = v[3][1] = 1;
	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < 2; j++) {
			v[i + 1][j ^ 1] = (v[i + 1][j ^ 1] + v[i][j]) % MOD;
			v[i + 2][j ^ 1] = (v[i + 2][j ^ 1] + v[i][j]) % MOD;
			v[i + 3][j ^ 1] = (v[i + 3][j ^ 1] + v[i][j]) % MOD;
		}
	}
	int N, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << v[N][1] << ' ' << v[N][0] << '\n';
	}

	return 0;
}
