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

vector<int> p, res;

bool isPrime(int X) {
	for (int i = 0; p[i] <= sqrt(X); i++) {
		if (X % p[i] == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	p.push_back(2);
	for (int i = 3; i <= 141; i += 2) if (isPrime(i)) p.push_back(i);
	for (int i = 0; i < p.size() - 1; i++) res.push_back(p[i] * p[i + 1]);

	int N;
	cin >> N;
	cout << res[upper_bound(res.begin(), res.end(), N) - res.begin()];

	return 0;
}