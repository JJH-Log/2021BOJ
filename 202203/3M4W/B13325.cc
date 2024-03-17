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

lld N, v[2097152];
lld res;

lld dfs(int now, int depth) {
	if (depth == N) return v[now];
	lld left = dfs(2 * now, depth + 1);
	lld right = dfs(2 * now + 1, depth + 1);
	res += abs(left - right);
	v[now] += max(left, right);
	return v[now];
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 2; i < (1 << N + 1); i++) {
		cin >> v[i];
		res += v[i];
	}
	dfs(1, 0);
	cout << res;

	return 0;
}