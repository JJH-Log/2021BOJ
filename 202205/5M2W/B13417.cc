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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int T, N;
char v[1001], ans[2010];
int l, r;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		l = r = 1000;
		for (int i = 0; i < N; i++) cin >> v[i];
		ans[l] = ans[r] = v[0];
		for (int i = 1; i < N; i++) {
			if (v[i] <= ans[l]) ans[--l] = v[i];
			else ans[++r] = v[i];
		}
		for (int i = l; i <= r; i++) cout << ans[i];
		cout << '\n';
	}

	return 0;
}