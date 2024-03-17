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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
set<string> S[51];
string s;
int sz, res;

string cword(string x, int idx) {
	string ans = x.substr(idx);
	return ans + x.substr(0, idx);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		sz = s.size();
		bool dup = false;
		for (int j = 0; j < sz && !dup ; j++) {
			if(S[sz].count(cword(s, j))) dup = true;
		}
		if (!dup) S[sz].insert(s);
	}
	for (int i = 1; i <= 50; i++) res += S[i].size();
	cout << res;
	
	return 0;
}
