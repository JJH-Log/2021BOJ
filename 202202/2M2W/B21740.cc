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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N;
vector<string> v;

bool cmp(string A, string B) {
	return A + B > B + A;
}

bool cmp2(string A, string B) {
	if (A.length() != B.length()) return A.length() > B.length();
	return A + B > B + A;
}

string rev(string s) {
	string ans = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '9') ans += '6';
		else if (s[i] == '6') ans += '9';
		else ans += s[i];
	}
	return ans;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, res, ret;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(rev(s));
	}
	ret = v[0];
	for (int i = 0; i < N; i++) if (cmp2(v[i], ret)) ret = v[i];
	v.push_back(ret);

	sort(v.begin(), v.end(), cmp);
	res = "";
	for (int i = 0; i < N + 1; i++) res += v[i];
	cout << rev(res);

	return 0;
}
