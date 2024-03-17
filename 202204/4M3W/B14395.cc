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

struct info {
	lld num;
	string state;
};

lld next(lld num, int op) {
	if (op == 0) return num * num;
	if (op == 1) return num + num;
	if (op == 2) return num - num;
	if (op == 3) {
		if (num == 0) return 0;
		return num / num;
	}
}

set<int> s;
queue<info> q;
lld a, b;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	if (a == b) {
		cout << 0;
		return 0;
	}
	
	s.insert(a);
	q.push({ a, "" });

	while (!q.empty()) {
		info now = q.front(); q.pop();
		if (now.num == b) {
			cout << now.state;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			lld tar = next(now.num, i);
			if (tar <= 1e9 && !s.count(tar)) {
				s.insert(tar);
				q.push({ tar, now.state + "*+-/"[i] });
			}
		}
	}
	cout << -1;

	return 0;
}