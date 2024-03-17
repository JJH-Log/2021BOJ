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
string s, tars;
int tar[26], ans[26], res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> s;
	for (auto c : s) tar[c - 'A']++;
	tars = s;
	for (int i = 1; i < N; i++) {
		fill(ans, ans + 26, 0);
		cin >> s;
		if (abs((int)tars.size() - (int)s.size()) > 1) continue;
		for (auto c : s) ans[c - 'A']++;
		int diff = 0;
		for (int i = 0; i < 26; i++) diff += abs(tar[i] - ans[i]);
		if (diff <= 1) res++;
		else if (diff == 2) {
			bool FLAG = true;
			for (int i = 0; i < 26; i++) if (abs(tar[i] - ans[i]) == 2) FLAG = false;
			if (FLAG) res++;
		}
	}
	cout << res;

	return 0;
}
