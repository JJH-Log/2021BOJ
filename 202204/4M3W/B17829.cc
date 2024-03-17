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

int N, v[1024][1024];

int check(int x, int y) {
	vector<int> tmp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) tmp.push_back(v[x + i][y + j]);
	}
	sort(tmp.begin(), tmp.end());
	return tmp[2];
}


int solve(int t) {
	for (int i = 0; i < t; i += 2) {
		for (int j = 0; j < t; j += 2) {
			v[i / 2][j / 2] = check(i, j);
		}
	}
	if (t == 1) return v[0][0];
	else return solve(t / 2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	cout << solve(N);

	return 0;
}