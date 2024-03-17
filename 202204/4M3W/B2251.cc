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

struct info {
	int t[3];
};

int v[3];
bool vtd[201][201][201];
bool res[201];
pii d[6] = { {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1} };
queue<info> q;

info move(info now, int i, int j) { //a->b
	int total = now.t[i] + now.t[j];
	now.t[j] = min(total, v[j]);
	now.t[i] = total - now.t[j];
	return now;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> v[0] >> v[1] >> v[2];
	vtd[0][0][v[2]] = 1;
	q.push({ 0, 0, v[2] });

	while (!q.empty()) {
		info now = q.front(); q.pop();
		if(now.t[0] == 0) res[now.t[2]] = 1;
		for (int i = 0; i < 6; i++) {
			info next = move(now, d[i].first, d[i].second);
			if (!vtd[next.t[0]][next.t[1]][next.t[2]]) {
				vtd[next.t[0]][next.t[1]][next.t[2]] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 0; i <= v[2]; i++) if (res[i]) cout << i << ' ';

	return 0;
}