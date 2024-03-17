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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string S, T;
int sz;
bool res;

set<string> s;


void solve(string now) {
	if (res || s.count(now)) return;
	s.insert(now);

	if (now.size() == sz) {
		if (now == S) res = true;
		return;
	}

	if (now.back() == 'A') solve(now.substr(0, now.size() - 1));
	reverse(now.begin(), now.end());
	if (now.back() == 'B') solve(now.substr(0, now.size() - 1));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> S >> T;
	sz = S.size();
	solve(T);
	cout << (res ? 1 : 0);

	return 0;
}