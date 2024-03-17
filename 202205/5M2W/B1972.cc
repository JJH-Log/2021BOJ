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

string s;

bool check(string x, int p) {
	set<string> S;
	for (int i = 0; i + p + 1 < x.size(); i++) {
		string tar = "";
		tar += x[i];
		tar += x[i + p + 1];
		S.insert(tar);
	}
	return (S.size() == x.size() - p - 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> s;
		if (s == "*") break;
		bool FLAG = true;
		for (int i = 0; FLAG && i < (int)s.size() - 1; i++) FLAG &= check(s, i);
		if (FLAG) cout << s << " is surprising.\n";
		else cout << s << " is NOT surprising.\n";
	}
	
	return 0;
}