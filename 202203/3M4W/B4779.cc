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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, tar;
void solve(lld n, bool bl) {
	if (bl) {
		for (int i = 0; i < n; i++) cout << ' ';
		return;
	}
	if (n == 1) {
		cout << '-';
		return;
	}
	solve(n / 3, 0);
	solve(n / 3, 1);
	solve(n / 3, 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (true) {
		cin >> N;
		if (cin.eof()) break;
		tar = pow(3, N);
		solve(tar, 0);
		cout << '\n';
	}

	return 0;
}