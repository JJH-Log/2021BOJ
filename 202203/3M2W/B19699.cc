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
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[9];
int w[9];
bool lock[9];
int N, M;
set<int> s;
set<int> res;

bool isPrime(int X) {
	set<int>::iterator it = s.begin();
	for (auto it = s.begin(); (*it) <= sqrt(X); it++) {
		if (X % (*it) == 0) return false;
	}
	return true;
}

void backTracking(int cnt) {
	if (cnt == M) {
		int ans = 0;
		for (int i = 0; i < M; i++) ans += v[w[i]];
		if (s.count(ans)) res.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!lock[i]) {
			lock[i] = 1;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	s.insert(2);
	for (int i = 3; i <= 10000; i += 2) if (isPrime(i)) s.insert(i);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];
	backTracking(0);
	if (res.size()) for (auto t : res) cout << t << ' ';
	else cout << -1;
	return 0;
}