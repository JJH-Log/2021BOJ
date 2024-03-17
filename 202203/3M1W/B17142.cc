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
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, res, cnt;
int v[50][50], _v[50][50];
vector<pii> vc;
queue<pii> q;
int w[10];

bool inRange(int x, int y) { return x >= 0 && x < N&& y >= 0 && y < N; }

void simulation() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) _v[i][j] = v[i][j] == 1 ? -2 : -1;
	}
	for (int i = 0; i < M; i++) {
		q.push(vc[w[i]]);
		_v[vc[w[i]].first][vc[w[i]].second] = 0;
	}
	int ans = 0;
	int ccnt = cnt;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		for (int i = 0; i < 4; i++) {
			int dx = x + "2011"[i] - '1';
			int dy = y + "1120"[i] - '1';
			if (inRange(dx, dy) && _v[dx][dy] == -1) {
				_v[dx][dy] = _v[x][y] + 1;
				q.push({ dx, dy });
				if (v[dx][dy] == 0) ans = max(ans, _v[dx][dy]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (_v[i][j] == -1) return;
		}
	}
	res = min(res, ans);
}


void BruteForce(int cnt, int idx) {
	if (cnt == M) {
		simulation();
		return;
	}
	for (int i = idx; i < vc.size(); i++) {
		w[cnt] = i;
		BruteForce(cnt + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			if (v[i][j] == 0) cnt++;
			if (v[i][j] == 2) vc.push_back({ i, j });
		}
	}
	res = 1e9;
	BruteForce(0, 0);
	if (res == 1e9) cout << -1;
	else cout << res;

	return 0;
}
