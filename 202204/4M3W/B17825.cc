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

struct state {
	int code, point, cnt;
};

int v[17] = { 1, 2, 3, 12, 5, 6, 12, 0, 9, 10, 11, 12, 13, 14, 15, 16, 16 };
int p[17] = { 10, 13, 16, 19, 20, 22, 24, 0, 30, 28, 27, 26, 25, 30, 35, 40, 0 };
queue<state> q;
map<int, int> m;

vector<int> decode(int X) {
	vector<int> ans;
	for (int i = 0; i < 4; i++) {
		ans.push_back(X % 40);
		X /= 40;
	}
	sort(ans.begin(), ans.end(), greater<int>());
	return ans;
}

bool isDup(vector<int> X) {
	set<int> s;
	for (auto tar : X) {
		if (tar == 36 || tar == 0) continue;
		if (s.count(tar)) return true;
		s.insert(tar);
	}
	return false;
}

int encode(vector<int> X) {
	sort(X.begin(), X.end());
	int ans = 0, t = 1;
	for (int i = 0; i < 4; i++) {
		ans += X[i] * t;
		t *= 40;
	}
	return ans;
}

int next(int now, int move) {
	if (now < 20) {
		if (now == 5 || now == 10 || now == 15) {
			int tar = ((now / 5) - 1) * 4;
			for (int i = 0; i < move; i++) tar = v[tar];
			return tar + 20;
		}
		else {
			if (now + move < 20) return now + move;
			if (now + move == 20) return 35;
			return 36;
		}
	}
	now -= 20;
	for (int i = 0; i < move; i++) {
		now = v[now];
		if (now == 16) return 36;
	}
	return now + 20;
}

int getPoint(int now) {
	if (now < 20) return now * 2;
	else return p[now - 20];
}

int res;
int w[10];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) cin >> w[i];

	m[0] = 0;
	q.push({ 0, 0, 0 });
	while (!q.empty()) {
		state now = q.front(); q.pop();
		res = max(res, now.point);

		vector<int> horse = decode(now.code);

		//if (m[now.code] != now.point) continue;
		if (now.cnt == 10) continue;

		for (int i = 0; i < 4; i++) {
			if (horse[i] == 36) continue;
			int tmp = horse[i];
			horse[i] = next(horse[i], w[now.cnt]);
			if (!isDup(horse)) {
				int next_code = encode(horse);
				int next_point = now.point + getPoint(horse[i]);
				if (!m.count(next_code) || m[next_code] < next_point) {
					m[next_code] = next_point;
					q.push({ next_code, next_point, now.cnt + 1 });
				}
			}
			horse[i] = tmp;
		}
	}
	cout << res;

	return 0;
}