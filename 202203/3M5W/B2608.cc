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

string tar = "_IVXLCDM";
int val[8] = { 0, 1, 5, 10, 50, 100, 500, 1000 };

string tar2[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
int val2[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

string s[2];
int v[2];

int decode(string X) {
	int ans = 0;
	for (int i = 0; i < X.size() - 1; i++) {
		if (val[tar.find(X[i])] < val[tar.find(X[i + 1])]) ans -= val[tar.find(X[i])];
		else ans += val[tar.find(X[i])];
	}
	return ans;
}

string encode(int X) {
	string ans = "";
	for (int i = 0; i < 13; i++) {
		while (X >= val2[i]) ans += tar2[i], X -= val2[i];
	}
	return ans;
}



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 2; i++) cin >> s[i], v[i] = decode(s[i] + '_');
	cout << v[0] + v[1] << '\n' << encode(v[0] + v[1]);

	return 0;
}