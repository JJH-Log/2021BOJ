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
int i;
bool FLAG;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	getline(cin, s);
	i = 0;
	for (int now = 0; now < s.size(); now++) {
		if (FLAG) { //inside tag
			if (s[now] == '>') {
				for (int t = i; t <= now; t++) res += s[t];
				FLAG = false;
				i = now + 1;
			}
		}
		else {
			if (s[now] == '<') {
				for (int t = now - 1; t >= i; t--) res += s[t];
				FLAG = true;
				i = now;
			}
			if (s[now] == ' ') {
				for (int t = now - 1; t >= i; t--) res += s[t];
				res += ' ';
				i = now + 1;
			}
		}
	}
	for (int t = s.size() - 1; t >= i; t--) res += s[t];
	cout << res;


	return 0;
}
