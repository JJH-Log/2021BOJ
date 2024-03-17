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

vector<int> v[26];
string s;
int res;

bool check(int i, int j, bool _swap) {
	if (v[i][0] < v[j][0] && v[j][0] < v[i][1] && v[i][1] < v[j][1]) return true;
	if (!_swap) return check(j, i, true);
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < 52; i++) v[s[i] - 'A'].push_back(i);

	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) if (check(i, j, 0)) res++;
	}
	cout << res;

	return 0;
}