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

lld N, K, S;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	S = (K + 1) * K / 2;
	if (N < S) cout << -1;
	else {
		N -= S;
		if (N % K) cout << K;
		else cout << K - 1;
	}
	
	return 0;
}
