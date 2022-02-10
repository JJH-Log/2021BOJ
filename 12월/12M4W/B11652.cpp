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
#define MAXLLD 9223372036854775807
using namespace std;
using lld = long long;
using pii = pair<int, int>;

map<lld, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, cnt;
	lld ans = MAXLLD;
	cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		lld x;
		cin >> x;
		if (!m.count(x)) m[x] = 1;
		else m[x]++;

		if (m[x] == cnt) ans = min(ans, x);
		else if (m[x] > cnt) {
			cnt = m[x];
			ans = x;
		}
	}
	cout << ans;
	return 0;
}
