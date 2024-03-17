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

vector<lld> v;
lld K;
int solve(lld now) {
	if (now == 1) return 0;
	return solve(now - v[lower_bound(v.begin(), v.end(), now) - v.begin() - 1]) ^ 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (lld i = 1; i <= 1e18; i <<= 1) v.push_back(i);
	cin >> K;
	cout << solve(K);
	
	return 0;
}