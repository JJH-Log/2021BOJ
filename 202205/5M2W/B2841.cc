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

int N, P, x, p, res;
stack<int> st[7];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> x >> p;
		while (!st[x].empty() && st[x].top() > p) {
			st[x].pop();
			res++;
		}
		if (!st[x].empty() && st[x].top() == p) continue;
		st[x].push(p);
		res++;
	}
	cout << res;

	return 0;
}