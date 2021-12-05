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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000000
#define BOUND 100000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	char c = '-';
	int cnt = 0;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != c) {
			c = s[i];
			cnt++;
		}
	}
	cout << cnt / 2;

	return 0;
}

