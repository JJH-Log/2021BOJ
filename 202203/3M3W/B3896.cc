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
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> v;
bitset<1299710> bs;

bool isPrime(int X) {
	for (int i = 1; v[i] * v[i] <= X; i++) {
		if (X % v[i] == 0) return false;
	}
	return true;
}

int solve(int X) {
	if (bs[X]) return 0;
	int l, r;
	l = X - 1; r = X + 1;
	while (!bs[l]) l--;
	while (!bs[r]) r++;
	return (r - l);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	v.push_back(0); bs[0] = 1;
	v.push_back(2); bs[2] = 1;
	for (int i = 3; i <= 1299709; i += 2) if (isPrime(i)) v.push_back(i), bs[i] = 1;
	int T, x;
	cin >> T;
	while (T--) {
		cin >> x;
		cout << solve(x) << '\n';
	}
	
	return 0;
}