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
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, v[10000];
set<int> s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];

	int idx, M;
	M = v[N - 1]; s.insert(v[N - 1]);
	for (idx = N - 2; idx >= 0; idx--) {
		s.insert(v[idx]);
		if (M < v[idx]) break;
		M = min(M, v[idx]);
	}
	if (idx == -1) cout << -1;
	else {
		set<int>::iterator it = lower_bound(s.begin(), s.end(), v[idx]); it--;
		int tar = (*it);
		it = s.begin();
		for (int i = N - 1; i > idx; i--) {
			if ((*it) == tar) it++;
			v[i] = (*it);
			it++;
		}
		v[idx] = tar;
		for (int i = 0; i < N; i++) cout << v[i] << ' ';
	}
	
	return 0;
}