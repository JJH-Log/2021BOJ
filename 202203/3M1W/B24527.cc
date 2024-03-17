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
#include <random>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld H, Q, R;
double v[100003];
vector<lld> p;
double ans[100003];
double pre[100003];

pll getInter(lld tar) {
	if (tar == 1) return { 1, H + 1 };
	lld idx = lower_bound(p.begin(), p.end(), tar) - p.begin();
	return { tar - p[idx - 1], tar - p[idx - 1] + H - idx };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << fixed;
	cout.precision(8);

	lld x, y;
	cin >> H >> Q >> R;

	lld a = 0, b = 1;
	while (p.size() != H) {
		a += b++;
		p.push_back(a);
	}

	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		pll se = getInter(x);
		int gap = se.second - se.first + 1;
		v[se.first] += (double)y / gap;
		v[se.second + 1] -= (double)y / gap;
	}
	for (int i = 1; i <= H + 1; i++) ans[i] = v[i] + ans[i - 1];
	for (int i = 1; i <= H + 1; i++) pre[i] = ans[i] + pre[i - 1];

	for (int i = 0; i < R; i++) {
		cin >> x >> y;
		cout << pre[y] - pre[x - 1] << '\n';
	}

	return 0;
}
