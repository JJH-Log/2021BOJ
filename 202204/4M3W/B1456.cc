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

lld A, B;
vector<int> pr;
int res;

bool isPrime(int X) {
	int x = sqrt(X);
	for (int i = 0; pr[i] <= x; i++) {
		if (X % pr[i] == 0) return false;
	}
	return true;
}

bool check(lld X) { 
	return (A <= X) && (X <= B);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B;

	pr.push_back(2);
	for (lld i = 4; i <= B; i *= 2) if (check(i)) res++;
	lld b = sqrt(B);
	for (lld i = 3; i <= b; i += 2) {
		if (isPrime(i)) {
			pr.push_back(i);
			if (check(i * i)) res++;
			if (i < 46416) for (lld j = i * i * i; j <= B; j *= i) if (check(j)) res++;
		}
	}
	cout << res;

	return 0;
}