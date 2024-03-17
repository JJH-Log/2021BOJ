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
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[100000], N, T, G;
queue<int> q;

int next(int now) {
	now *= 2;
	int t = 1;
	while (now - t * 10 >= 0) t *= 10;
	return now - t;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fill(v, v + 100000, 1e9);
	cin >> N >> T >> G;
	v[N] = 1;
	q.push(N);
	
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (v[now] == T + 1) continue;
		if (now + 1 < 100000 && v[now + 1] > v[now] + 1) {
			v[now + 1] = v[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 < 100000 && v[next(now)] > v[now] + 1) {
			v[next(now)] = v[now] + 1;
			q.push(next(now));
		}
	}
	if (v[G] == 1e9) cout << "ANG";
	else cout << v[G] - 1;

	return 0;
}