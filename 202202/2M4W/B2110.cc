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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, C;
int v[200000];

int ans(int step) {
	int x = v[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (v[i] - x >= step) {
			x = v[i];
			cnt++;
		}
	}
	//cout << "cnt : " << cnt << endl;
	return cnt;
}

int solve(int lo, int hi) {
	if (lo > hi) return (lo - 1);
	int mid = (lo + hi) / 2;
	if (ans(mid) < C) return solve(lo, mid - 1);
	else return solve(mid + 1, hi);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	cout << solve(1, 1e9);

	return 0;
}
