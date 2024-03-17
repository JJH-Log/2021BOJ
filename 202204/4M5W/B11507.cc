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

string tar = "PKHT";
string s, tmp;
set<string> S[4];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	for (int i = 0; i < s.size(); i += 3) {
		int idx = tar.find(s[i]);
		tmp = s.substr(i, 3);
		if (S[idx].count(tmp)) {
			cout << "GRESKA";
			return 0;
		}
		else S[idx].insert(tmp);
	}
	for (int i = 0; i < 4; i++) cout << 13 - S[i].size() << ' ';

	return 0;
}
