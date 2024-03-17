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

bool isCapital(char x) { return (x >= 'A') && (x <= 'Z'); }

bool FLAG1(string x) {
	if (x[0] == '_' || x.back() == '_') return false;
	for (auto c : x) {
		if ((c >= 'a' && c <= 'z') || c == '_') continue;
		return false;
	}
	return true;
}

bool FLAG2(string x) {
	if (isCapital(x[0])) return false;
	for (auto c : x) {
		if ((c >= 'a' && c <= 'z') || isCapital(c)) continue;
		return false;
	}
	return true;
}



bool FLAG3(string x) { return (x.find("__") != string::npos); }

bool FLAG4(string x) {
	for (auto c : x) {
		if (c < 'a' || c > 'z') return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	if ((FLAG1(s) && FLAG2(s) && !FLAG4(s)) || (!FLAG1(s) && !FLAG2(s)) || FLAG3(s)) cout << "Error!";
	else {
		bool check = false;
		for (auto c : s) {
			if (isCapital(c)) {
				res += '_';
				res += c + 32;
			}
			else if (c == '_') check = true;
			else {
				if (check) res += c - 32;
				else res += c;
				check = false;
			}
		}
		cout << res;
	}
	return 0;
}