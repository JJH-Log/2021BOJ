#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int odd = -1;
	string s, ans;
	v.resize(26, 0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) v[s[i] - 'A']++;
	for (int i = 0; i < 26; i++) {
		if (v[i] % 2) {
			if (odd == -1) odd = i;
			else {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}
	ans = "";
	for (int i = 0; i < 26; i++) for (int j = 0; j < v[i] / 2; j++) ans += 'A' + i;
	if (odd != -1) ans += 'A' + odd;
	for (int i = 25; i >= 0; i--) for (int j = 0; j < v[i] / 2; j++) ans += 'A' + i;
	cout << ans;

	return 0;
}