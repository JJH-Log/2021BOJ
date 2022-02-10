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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


int N, v[100];

int gcd(int x, int y) {
	if (!y) return x;
	if (x < y) return gcd(y, x);
	return gcd(y, x % y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 1; i < N; i++) {
		cout << v[0] / gcd(v[0], v[i]) << "/" << v[i] / gcd(v[0], v[i]) << '\n';
	}

	return 0;
}
