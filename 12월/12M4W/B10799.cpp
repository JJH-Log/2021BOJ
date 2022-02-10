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
#define MOD 15746
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

string s;
int bf;

int parse(char x) {
	return x == '(' ? 0 : 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	bf = 0;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (parse(s[i]) == 0) cnt++, bf = 0;
		else {
			if (bf == 1) ans++;
			else ans += cnt - 1;
			cnt--, bf = 1;
		}
	}
	cout << ans;

	return 0;
}
