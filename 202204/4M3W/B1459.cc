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

lld X, Y, W, S, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> X >> Y >> W >> S;
	res = (X + Y) * W;
	res = min(res, min(X, Y) * S + abs(X - Y) * W);
	if ((X + Y) % 2) res = min(res, (max(X, Y) - 1) * S + W);
	else res = min(res, max(X, Y) * S);
	cout << res;

	return 0;
}