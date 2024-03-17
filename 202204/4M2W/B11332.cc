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

string tar[5] = { "O(N)", "O(N^2)", "O(N^3)", "O(2^N)", "O(N!)" };

string s;
lld N, T, L;
bool func(int op) {
	if (op == 0) return T * N <= L;
	if (op == 1) return (T * N * N) <= L;
	if (op == 2) return (N * N * N) <= (double)(L / T);
	if (op == 3) {
		lld now = T;
		for (int t = 1; t <= N; t++) {
			now *= 2;
			if (now > L) return false;
		}
		return true;
	}
	if (op == 4) {
		lld now = T;
		for (int t = 1; t <= N; t++) {
			now *= t;
			if (now > L) return false;
		}
		return true;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C;
	cin >> C;
	while (C--) {
		cin >> s >> N >> T >> L;
		L *= 1e8;
		
		for (int i = 0; i < 5; i++) {
			if (tar[i] == s) {
				if (func(i)) cout << "May Pass.\n";
				else cout << "TLE!\n";
			}
		}
	}

	return 0;
}