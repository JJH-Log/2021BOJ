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
#include <regex>
#define MOD 1234567
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
string vo = "aeiou";
string x, y;
string rx, ry;
int cnt[26];

bool check1() {
	for (int i = 0; i < 26; i++) if (cnt[i]) return false;
	return true;
}

bool check2() {
	return (x[0] == y[0]) && (x.back() == y.back());
}

bool check3() {	 
	return rx == ry;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> x >> y;
	for (auto c : x) cnt[c - 'a']++;
	for (auto c : y) cnt[c - 'a']--;
	for (auto c : x) if (vo.find(c) == string::npos) rx += c;
	for (auto c : y) if (vo.find(c) == string::npos) ry += c;
	if (check1() && check2() && check3()) cout << "YES";
	else cout << "NO";

	return 0;
}