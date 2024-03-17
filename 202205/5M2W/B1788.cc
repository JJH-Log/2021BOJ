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
#include <regex>
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
int a, b, t;
bool FLAG;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	a = 0, b = 1;
	if (N < 0) {
		if(N % 2 == 0) FLAG = true;
		N = abs(N);
	}
	for (int i = 0; i < N; i++) {
		t = (a + b) % MOD;
		a = b;
		b = t;
	}
	if (FLAG) cout << -1;
	else if (a == 0) cout << 0;
	else cout << 1;
	cout << '\n' << a;
	
	return 0;
}