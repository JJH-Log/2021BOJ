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
#include <regex>
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int T;
string s, tar;

string make_regex(string x) {
	int idx = x.find('*');
	string ans = x.substr(0, idx);
	ans += "[a-z]*";
	ans += x.substr(idx + 1);
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T >> tar;
	regex re(make_regex(tar));

	while (T--) {
		cin >> s;
		if (regex_match(s, re)) cout << "DA\n";
		else cout << "NE\n";
	}

	return 0;
}