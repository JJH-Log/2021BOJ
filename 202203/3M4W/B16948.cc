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

struct pos {
	int x, y;
};

int N, v[200][200];

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < N); }
queue<pos> q;
pos S, E;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	cin >> N;
	cin >> S.x >> S.y >> E.x >> E.y;

	v[S.x][S.y] = 1;
	q.push({ S.x, S.y });

	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int dx = now.x + "002244"[i] - '2';
			int dy = now.y + "130413"[i] - '2';
			if (inRange(dx, dy) && !v[dx][dy]) {
				v[dx][dy] = v[now.x][now.y] + 1;
				q.push({ dx, dy });
			}
		}
	}
	cout << v[E.x][E.y] - 1;

	return 0;
}