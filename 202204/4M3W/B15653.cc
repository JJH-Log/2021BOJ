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

struct pos {
	int x, y;
	bool operator==(pos t) {
		return x == t.x && y == t.y;
	}
};

struct state {
	int cnt;
	pos r, b;
};

set<int> s;
int N, M;
int v[10][10];
pos R, B, O;
queue<state> q;

int encode(pos r, pos b) { return r.x * 0xFFF + r.y * 0xFF + b.x * 0xF + b.y; }

pos move(pos now, pos other, int d) {
	int dx = now.x + "2011"[d] - '1';
	int dy = now.y + "1120"[d] - '1';
	if (pos{ dx, dy } == O) return { -1, -1 };
	if (pos{ dx, dy } == other || v[dx][dy]) return now;
	return move({ dx, dy }, other, d);
}

int check(pos r, pos b) {
	int ans = 0;
	if (r == pos{ -1, -1 }) ans += 2;
	if (b == pos{ -1, -1 }) ans += 1;
	return ans;
}

bool asks(int op, pos r, pos b) {
	if (op == 0) return r.x >= b.x;
	if (op == 1) return r.x <= b.x;
	if (op == 2) return r.y >= b.y;
	if (op == 3) return r.y <= b.y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			v[i][j] = s[j] == '#' ? 1 : 0;
			if (s[j] == 'R') R = { i, j };
			if (s[j] == 'B') B = { i, j };
			if (s[j] == 'O') O = { i, j };
		}
	}
	s.insert(encode(R, B));
	q.push({ 0, R, B });
	while (!q.empty()) {
		state now = q.front(); q.pop();
		pos tr, tb;
		for (int i = 0; i < 4; i++) {
			if (asks(i, now.r, now.b)) { tr = move(now.r, now.b, i); tb = move(now.b, tr, i); }
			else { tb = move(now.b, now.r, i); tr = move(now.r, tb, i); }
			int ans = check(tr, tb);
			if (ans == 2) {
				cout << now.cnt + 1;
				return 0;
			}
			if (ans == 0 && !s.count(encode(tr, tb))) {
				s.insert(encode(tr, tb));
				q.push({ now.cnt + 1, tr, tb });
			}
		}
	}
	cout << -1;
	return 0;
}