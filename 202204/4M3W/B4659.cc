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

string s;
string vo = "aeiou";

bool check1() {
	for (auto c : s) {
		if (vo.find(c) != string::npos) return true;
	}
	return false;
}

bool check2() {
	int j, m;
	j = m = 0;
	for (auto c : s) {
		if (vo.find(c) != string::npos) j++, m = 0;
		else j = 0, m++;
		if (j == 3 || m == 3) return false;
	}
	return true;
}

bool check3() {
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (true) {
		cin >> s;
		if (s == "end") break;
		if (check1() && check2() && check3()) cout << "<" << s << "> is acceptable.\n";
		else cout << "<" << s << "> is not acceptable.\n";
	}

	return 0;
}