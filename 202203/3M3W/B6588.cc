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
#define BOUND 1000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 2002
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

bitset<BOUND> bs;
vector<int> pr;

bool isPrime(int X) {
	for (int i = 0; pr[i] <= sqrt(X); i++) {
		if (X % pr[i] == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pr.push_back(2), bs[2] = 1;
	for (int i = 3; i < BOUND; i += 2)  if (isPrime(i)) pr.push_back(i), bs[i] = 1;
	int N;

	while (true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 1; pr[i] <= N / 2; i++) {
			if (bs[pr[i]] && bs[N - pr[i]]) {
				cout << N << " = " << pr[i] << " + " << N - pr[i] << '\n';
				break;
			}
		}
	}

	return 0;
}