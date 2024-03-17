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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, X;
int v[250001];
lld w[250001];
lld res, cnt;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		w[i] = w[i - 1] + v[i];
	}
	for (int i = X; i <= N; i++) {
		lld ans = w[i] - w[i - X];
		if (ans > res) {
			res = ans;
			cnt = 1;
		}
		else if (ans == res) cnt++;
	}
	if (!res) cout << "SAD";
	else cout << res << '\n' << cnt;

	return 0;
}