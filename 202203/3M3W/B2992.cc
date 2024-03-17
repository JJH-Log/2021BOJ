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
#include <numeric>
#define MOD 1000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string s;
set<int> S;
int w[6];
bool lock[6];


void backTracking(int cnt) {
	if (cnt == s.size()) {
		string ans = "";
		for (int i = 0; i < s.size(); i++) ans += s[w[i]];
		S.insert(stoi(ans));
	}
	for (int i = 0; i < s.size(); i++) {
		if (!lock[i]) {
			lock[i] = true;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	cin >> s;
	backTracking(0);
	set<int>::iterator it = lower_bound(S.begin(), S.end(), stoi(s));
	it++;
	if (it == S.end()) cout << 0;
	else cout << (*it);

	return 0;
}