#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<bool>> v;
vector<vector<bool>> vtd;
vector<vector<vector<bool>>> w;
vector<int> rv;
int N, K, R;


int dfs(int x, int y) {
	int result;
	result = v[x][y] ? 1 : 0;
	for (int i = 0; i < 4; i++) {
		if (w[x][y][i]) {
			int dx = x + "2011"[i] - '1';
			int dy = y + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < N && !vtd[dx][dy]) {
				vtd[dx][dy] = 1;
				result += dfs(dx, dy);
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> R;
	w.resize(N, vector<vector<bool>>(N, vector<bool>(4, 1))); //NSEW
	v.resize(N, vector<bool>(N, 0));
	vtd.resize(N, vector<bool>(N, 0));

	int x1, y1, x2, y2, total;
	for (int i = 0; i < R; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		if (x1 < x2) w[x1][y1][0] = 0, w[x2][y2][1] = 0;
		if (x1 > x2) w[x1][y1][1] = 0, w[x2][y2][0] = 0;
		if (y1 < y2) w[x1][y1][2] = 0, w[x2][y2][3] = 0;
		if (y1 > y2) w[x1][y1][3] = 0, w[x2][y2][2] = 0;
	}
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1;
		x1--, y1--;
		v[x1][y1] = 1;
	}
	total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vtd[i][j]) {
				vtd[i][j] = 1;
				int ans = dfs(i, j);
				if (ans) {
					total += ans;
					rv.push_back(ans);
				}
			}
		}
	}

	lld result = 0;
	for (int i = 0; i < rv.size(); i++) {
		for (int j = i + 1; j < rv.size(); j++) {
			result += (lld)rv[i] * rv[j];
		}
	}
	cout << result;


	return 0;
}