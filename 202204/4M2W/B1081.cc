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

string s1, s2;
lld res;

lld _stoi(string x) {
	if (!x.size()) return 0;
	else return stoi(x);
}

lld total(string x) {
	int t = 1;
	lld ans = 0;
	for (int i = x.size() - 1; i >= 0; i--, t *= 10) {
		for (int j = 0; j <= 9; j++) {
			if (j < x[i] - '0') ans += (_stoi(x.substr(0, i)) + 1) * t * j;
			if (j == x[i] - '0') ans += (_stoi(x.substr(0, i))) * t * j + (_stoi(x.substr(i + 1)) + 1) * j;
			if (j > x[i] - '0') ans += (_stoi(x.substr(0, i))) * t * j;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> s1 >> s2;
	res = total(s2) - total(s1);
	for (auto c : s1) res += c - '0';
	cout << res;
	
	return 0;
}