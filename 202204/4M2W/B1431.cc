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


vector<string> s;
string tmp;

int getID(string x) {
	int res = 0;
	for (auto c : x) res += ((c >= '0' && c <= '9') ? c - '0' : 0);
	return res;
}

bool compare(string x, string y) {
	if (x.size() == y.size()) {
		int xl = getID(x);
		int yl = getID(y);
		if (xl == yl) return x < y;
		else return xl < yl;
	}
	return x.size() < y.size();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> tmp;
		s.push_back(tmp);
	}
	sort(s.begin(), s.end(), compare);
	for (auto tar : s) cout << tar << '\n';

	return 0;
}