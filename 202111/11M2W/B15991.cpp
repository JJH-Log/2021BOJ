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

int v[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v[0] = v[1] = 1;
	v[2] = 2;
	v[3] = 4;
	for (int i = 4; i <= 50000; i++) v[i] = ((lld)v[i - 3] + v[i - 2] + v[i - 1]) % MOD;

	int N, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 1) cout << 1;
		else if (N % 2) cout << (v[(N - 1) / 2] + v[(N - 3) / 2]) % MOD;
		else cout << (v[N / 2] + v[(N - 2) / 2]) % MOD;
		cout << '\n';
	}


	return 0;
}
