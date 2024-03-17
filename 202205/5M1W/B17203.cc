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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, Q;
int v[1001];
int x, y, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> v[i];
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		if (x == y) cout << 0 << '\n';
		else {
			res = 0;
			for (int i = x + 1; i <= y; i++) res += abs(v[i] - v[i - 1]);
			cout << res << '\n';
		}
	}


	return 0;
}