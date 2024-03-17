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

struct pos { int x, y; };

int getDist(pos a, pos b) { return abs(a.x - b.x) + abs(a.y - b.y); }
int N, M, D, res;
vector<pos> E;

int getShortest(pos x, vector<pos> enemy) {
	int dist, ans;
	ans = 0, dist = getDist(x, enemy[0]);
	for (int i = 1; i < enemy.size(); i++) {
		int now = getDist(x, enemy[i]);
		if (now < dist) ans = i, dist = now;
		else if (now == dist && enemy[i].y < enemy[ans].y) ans = i, dist = now;
	}
	return ans;
}

int simulation(int x[], vector<pos> enemy) {
	if (enemy.size() == 0) return 0;
	
	set<int> check;
	vector<pos> next_state;

	for (int i = 0; i < 3; i++) {
		pos archer = { N, x[i] };
		int idx = getShortest( archer, enemy);
		if (getDist(archer, enemy[idx]) <= D) check.insert(idx);
	}
	int ans = check.size();

	for (int i = 0; i < enemy.size(); i++) {
		if (check.count(i)) continue;
		if (enemy[i].x == N - 1) continue;
		next_state.push_back({ enemy[i].x + 1, enemy[i].y });
	}

	return ans + simulation(x, next_state);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> D;
	int x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x;
			if (x) E.push_back({ i, j });
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				int tmp[3] = { i, j, k };
				res = max(res, simulation(tmp, E));
			}
		}
	}
	cout << res;


	return 0;
}