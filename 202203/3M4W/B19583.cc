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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

map<string, pair<bool, bool>> m;

int decode(string t) { return 600 * t[0] + 60 * t[1] + 10 * t[3] + t[4] - ('0' * 671); }
int A, B, C, T, res;

string x, y, z;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y >> z;
	A = decode(x), B = decode(y), C = decode(z);

	while (true) {
		cin >> x;
		if (cin.eof()) break;
		cin >> y;

		T = decode(x);
		if (A < T && T < B) continue;

		if (!m.count(y)) m[y] = { 0, 0 };
		T = decode(x);
		if (T <= A) m[y].first = 1;
		if (B <= T && T <= C) m[y].second = 1;
	}
	for (auto tar : m) if (tar.second.first && tar.second.second) res++;
	cout << res;

	return 0;
}