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


string s, res;

bool _fill(int n, bool op) {
	if (n % 2) return false;
	while (n >= 4) {
		res += "AAAA";
		n -= 4;
	}
	while (n) {
		res += "BB";
		n -= 2;
	}
	if (op) res += '.';
	return true;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			if (_fill(cnt, true)) cnt = 0;
			else {
				cout << -1;
				return 0;
			}
		}
		else cnt++;
	}
	if (!_fill(cnt, false)) {
		cout << -1;
		return 0;
	}
	cout << res;

	return 0;
}