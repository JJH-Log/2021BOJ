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
#include <sstream>
#define MOD 9901
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

stack<lld> s;
int p2; //Code reference from WeissBlume
bool FLAG;

void printing() {
	stack<lld> rs;
	while (!s.empty()) {
		rs.push(s.top());
		s.pop();
	}
	while (!rs.empty()) {
		cout << (rs.top() << p2) << ' ';
		s.push(rs.top());
		rs.pop();
	}
}

void solve(lld X, int idx) {
	lld tar = sqrt(X);
	if (idx == 3) {
		if (tar * tar == X) {
			FLAG = false;
			s.push(tar);
			printing();
			s.pop();
		}
	}
	else {
		int cnt = 0;
		for (lld tar = sqrt(X); cnt <= 1000 && FLAG && tar >= 0; tar--) {
			s.push(tar);
			solve(X - tar * tar, idx + 1);
			s.pop();
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld X;
	cin >> X;
	while (X % 4 == 0) ++p2, X >>= 2; //Code reference from WeissBlume
	FLAG = true;
	solve(X, 0);

	return 0;
}
