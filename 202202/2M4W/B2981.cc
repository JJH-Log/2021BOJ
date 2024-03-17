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
#define MAXS 500000
using namespace std;
using lld = long long;
using pii = pair<int, int>;



int v[100];
stack<int> s;
vector<int> ans;
int N, now;

int gcd(int x, int y) {
	if (y == 0) return x;
	if (x < y) return gcd(y, x);
	return gcd(y, x % y);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) s.push(abs(v[i] - v[j]));
	}
	while (!s.empty()) {
		if (!now) now = s.top();
		else now = gcd(now, s.top());
		s.pop();
	}

	for (int i = 1; i <= sqrt(now); i++) {
		if (now % i == 0) {
			if (now != i * i) ans.push_back(now / i);
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());

	for (auto t : ans) if(t != 1) cout << t << ' ';

	return 0;
}
