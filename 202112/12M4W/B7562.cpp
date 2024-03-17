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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct pos {
	int x, y;
};

pos S, E, mov[8] = { {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1} };
int T, N;
int v[300][300];
queue<pos> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		cin >> S.x >> S.y >> E.x >> E.y;
		v[S.x][S.y] = 1;
		q.push(S);

		while (!q.empty()) {
			pos now = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int dx = now.x + mov[i].x;
				int dy = now.y + mov[i].y;
				if (dx >= 0 && dx < N && dy >= 0 && dy < N && !v[dx][dy]) {
					v[dx][dy] = v[now.x][now.y] + 1;
					q.push({ dx, dy });
				}
			}
		}

		cout << v[E.x][E.y] - 1 << '\n';
		memset(v, 0, sizeof v);
	}
	
	
	return 0;
}
