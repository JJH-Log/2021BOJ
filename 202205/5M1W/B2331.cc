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

int A, P;
vector<int> v;
map<int, int> m;
int cnt;
int p[10];

void getP() {
	for (int i = 0; i < 10; i++) {
		int x = i;
		for (int j = 1; j < P; j++) x *= i;
		p[i] = x;
	}
}

int next(int t) {
	int ans = 0;
	while (t) {
		ans += p[t % 10];
		t /= 10;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> P;
	getP();
	v.push_back(A);
	m[A] = ++cnt;

	while (true) {
		A = next(A);
		if (m.count(A)) break;
		v.push_back(A);
		m[A] = ++cnt;
	}
	cout << m[A] - 1;
	
	return 0;
}
