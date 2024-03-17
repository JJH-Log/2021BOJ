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

vector<int> pr;

bool isPrime(int X) {
	if (X == 1) return false;
	for (int i = 0; pr[i] <= sqrt(X); i++) {
		if (X % pr[i] == 0) return false;
	}
	return true;
}

bool isUnderPrime(int X) {
	int cnt = 0;
	for (int i = 0; pr[i] <= sqrt(X); i++) {
		while (X % pr[i] == 0) {
			X /= pr[i];
			cnt++;
		}
	}
	return isPrime(cnt + (X != 1));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	pr.push_back(2);
	for (int i = 3; i < 100000; i += 2) if (isPrime(i)) pr.push_back(i);

	int A, B, res;
	cin >> A >> B;
	res = 0;
	for (int i = A; i <= B; i++) if(isUnderPrime(i)) res++;
	cout << res;

	return 0;
}