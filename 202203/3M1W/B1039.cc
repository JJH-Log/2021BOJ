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

string s;
bitset<11000000> bs;
int M, res;

string swaps(string tar, int x, int y) {
	string ans = "";
	for (int i = 0; i < tar.size(); i++) {
		if (i == x) ans += tar[y];
		else if (i == y) ans += tar[x];
		else ans += tar[i];
	}
	return ans;
}

void check(int cnt, string now) {
	if (cnt == M) {
		res = max(res, stoi(now));
		return;
	}
	for (int i = 0; i < now.size(); i++) {
		for (int j = i + 1; j < now.size(); j++) {
			string next = swaps(now, i, j);
			if (next[0] != '0' && !bs[stoi(next) + cnt * 1000000]) {
				bs[stoi(next) + cnt * 1000000] = 1;
				check(cnt + 1, next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s >> M;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) if (s[i] != '0') cnt++;
	if (cnt == 1) {
		if (stoi(s) < 100) cout << -1;
		else cout << stoi(s);
	}
	else {
		check(0, s);
		cout << res;
	}
	return 0;
}
