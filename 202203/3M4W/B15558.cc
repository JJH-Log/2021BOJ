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

struct info {
	int t, x, y;
};

int N, K;
string s[2];
bool res, vtd[2][100000];
queue<info> q;

void _push(int t, int x, int y) {
	vtd[x][y] = 1;
	q.push({ t, x, y });
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K >> s[0] >> s[1];
	_push(0, 0, 0);
	while (!q.empty()) {
		info now = q.front(); q.pop();
		if (now.y >= N - K) {
			res = true;
			break;
		}
		if (s[now.x][now.y + 1] == '1' && !vtd[now.x][now.y + 1]) _push(now.t + 1, now.x, now.y + 1);
		if (s[now.x][now.y - 1] == '1' && now.t != now.y - 1 && !vtd[now.x][now.y - 1]) _push(now.t + 1, now.x, now.y - 1);
		if (s[now.x ^ 1][now.y + K] == '1' && !vtd[now.x ^ 1][now.y + K]) _push(now.t + 1, now.x ^ 1, now.y + K);
	}
	cout << res;
	return 0;
}