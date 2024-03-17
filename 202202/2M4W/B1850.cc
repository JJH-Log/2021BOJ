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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;

lld gcd(lld X, lld Y) {
	if (Y == 0) return X;
	if (X < Y) return gcd(Y, X);
	return gcd(Y, X % Y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	lld ans, N, M;
	cin >> N >> M;
	ans = gcd(N, M);
	for (int i = 0; i < ans; i++) cout << '1';
	
	
	return 0;
}
