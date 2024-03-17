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
using pll = pair<lld, lld>;

vector<int> p;
set<int> s;
int v[78498];
int N, cnt;

bool isPrime(int X) {
	for (int i = 0; p[i] * p[i] <= X; i++) {
		if (X % p[i] == 0) return false;
	}
	return true;
}

void enroll(int X) {
	p.push_back(X);
	s.insert(X);
}

void solve(int X, int now, bool isPr) {
	if (X == 1) return;
	if (isPr || p[now] * p[now] > X) {
		int idx = lower_bound(p.begin(), p.end(), X) - p.begin();
		v[idx]++;
		if (v[idx] % 2) cnt++;
		else cnt--;
		return;
	}
	if (X % p[now] == 0) {
		if (v[now] % 2) cnt--;
		while (X % p[now] == 0) {
			X /= p[now];
			v[now]++;
		}
		if (v[now] % 2) cnt++;
	}
	solve(X, now + 1, 0);
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	enroll(2);
	for (int i = 3; i <= 1000000; i += 2) if (isPrime(i)) enroll(i);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		solve(x, 0, (bool)s.count(x));
		if (cnt) cout << "NE\n";
		else cout << "DA\n";
	}


	return 0;
}
