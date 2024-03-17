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
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string s1, s2;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s1 >> s2;
	v.resize(s2.size(), 0);

	int i, j;
	for (i = 1, j = 0; i < s2.size(); i++) {
		while (j && s2[j] != s2[i]) j = v[j - 1];
		if (s2[j] == s2[i]) v[i] = ++j;
	}
	for (i = 0, j = 0; i < s1.size(); i++) {
		while (j && s2[j] != s1[i]) j = v[j - 1];
		if (s2[j] == s1[i]) j++;
		if (j == s2.size()) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
