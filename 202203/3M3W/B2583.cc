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
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 2002
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y;
};

int v[100][100];
int N, M, K;
queue<pos> q;
vector<int> res;

int bfs(int x, int y) {
	int cnt;
	cnt = v[x][y] = 1;
	q.push({ x, y });
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + "2011"[i] - '1';
			int dy = now.y + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && v[dx][dy] == 0) {
				v[dx][dy] = 1;
				q.push({ dx, dy });
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++){
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) v[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!v[i][j]) res.push_back(bfs(i, j));
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto t : res) cout << t << ' ';


	return 0;
}