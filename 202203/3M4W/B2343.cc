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

int N, M;
int v[100000];

int solve(int lo, int hi) {
	if (lo == hi) return lo;
	int mid = (lo + hi) / 2;
	int ans = 1;
	int total = 0;
	for (int i = 0; i < N; i++) {
		if (mid < v[i]) return solve(mid + 1, hi);
		total += v[i];
		if (total > mid) {
			ans++;
			total = v[i];
		}
	}
	if (ans > M) return solve(mid + 1, hi);
	else return solve(lo, mid);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << solve(1, 1e9);

	return 0;
}