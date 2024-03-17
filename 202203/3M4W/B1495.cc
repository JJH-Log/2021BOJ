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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int idx, vol;
};

int N, S, M, res;
int v[50];
bool vtd[51][1001];
queue<info> q;

void _push(int idx, int vol) {
	vtd[idx][vol] = true;
	q.push({ idx, vol });
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++) cin >> v[i];
	_push(0, S);

	res = -1;
	while (!q.empty()) {
		info now = q.front(); q.pop();
		if (now.idx == N) {
			res = max(res, now.vol);
			continue;
		}
		if (now.vol + v[now.idx] <= M && !vtd[now.idx + 1][now.vol + v[now.idx]]) _push(now.idx + 1, now.vol + v[now.idx]);
		if (now.vol - v[now.idx] >= 0 && !vtd[now.idx + 1][now.vol - v[now.idx]]) _push(now.idx + 1, now.vol - v[now.idx]);
	}
	cout << res;

	return 0;
}