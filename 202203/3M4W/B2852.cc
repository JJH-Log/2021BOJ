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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int decode(string s) {
	return s[0] * 600 + s[1] * 60 + s[3] * 10 + s[4] - ('0' * 671);
}

string encode(int X) {
	string ans = "";
	ans += '0' + X / 600;
	X %= 600;
	ans += '0' + X / 60;
	X %= 60;
	ans += ':';
	ans += '0' + X / 10;
	X %= 10;
	return ans + (char)('0' + X);
}

int N, x;
int t[2880];
int cnt[2], res[2];
string tmp;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> tmp;
		t[decode(tmp)] = x;
	}
	for (int i = 0; i < 2880; i++) {
		if (t[i]) cnt[t[i] - 1] ++;
		if (cnt[0] > cnt[1]) res[0]++;
		if (cnt[0] < cnt[1]) res[1]++;
	}
	cout << encode(res[0]) << '\n' << encode(res[1]);

	return 0;
}