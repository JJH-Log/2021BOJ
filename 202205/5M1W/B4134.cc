#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld T, N;

bool isPrime(lld x) {
	if (x == 0 || x == 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (lld i = 3; i * i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while (T--) {
		cin >> N;
		while (!isPrime(N)) N++;
		cout << N << '\n';
	}
	
	return 0;
}
