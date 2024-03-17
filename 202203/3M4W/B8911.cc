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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct turtle {
	int x, y, d;
	turtle(int x, int y, int d) :x(x), y(y), d(d) {}
};

int xl, xr, yl, yr;
string s;
//string d[2] = {"0121", ""}

void update(int x, int y) {
	xl = min(xl, x), xr = max(xr, x);
	yl = min(yl, y), yr = max(yr, y);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		xl = xr = yl = yr = 0;
		turtle t(0, 0, 0);
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'F') {
				t.x += "0121"[t.d] - '1';
				t.y += "1210"[t.d] - '1';
			}
			if (s[i] == 'B') {
				t.x -= "0121"[t.d] - '1';
				t.y -= "1210"[t.d] - '1';
			}
			if (s[i] == 'R') t.d = (t.d + 1) % 4;
			if (s[i] == 'L') t.d = (t.d + 3) % 4;
			update(t.x, t.y);
		}
		cout << (xr - xl) * (yr - yl) << '\n';
	}

	
	

	return 0;
}