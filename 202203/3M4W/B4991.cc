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
	int t, x, y, state;
};

int v[20][20];
bool vtd[2048][20][20];
int N, M, num;
string s;
info S;
queue<info> q;

bool inRange(int x, int y) { return (x >= 0) && (x < N) && (y >= 0) && (y < M); }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	while (true) {
		cin >> M >> N;
		if (!N) break;
 
		for (int i = 0; i < N; i++) {
			cin >> s;
			for (int j = 0; j < M; j++) {
				if (s[j] == 'o') S = { 0, i, j, 1 };
				if (s[j] == 'x') v[i][j] = 1;
				else if (s[j] == '*') v[i][j] = --num;
				else v[i][j] = 0;
			}
		}
		vtd[1][S.x][S.y] = true;
		q.push(S);
		info now;
		while (!q.empty()) {
			now = q.front(); q.pop();
			if (now.state == ((1 << (-num + 1)) - 1)) break;
			for (int i = 0; i < 4; i++) {
				int dx = now.x + "2011"[i] - '1';
				int dy = now.y + "1120"[i] - '1';
				if (inRange(dx, dy) && v[dx][dy] < 1) {
					int ds = now.state | (1 << -v[dx][dy]);
					if (!vtd[ds][dx][dy]) {
						vtd[ds][dx][dy] = true;
						q.push({ now.t + 1, dx, dy, ds });
					}

				}
			}
		}
		if (now.state == ((1 << (-num + 1)) - 1)) cout << now.t << '\n';
		else cout << -1 << '\n';
		
		while (!q.empty()) q.pop();
		num = 0;
		for (int i = 0; i < 1024; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) vtd[i][j][k] = 0;
			}
		}
	}
	
	return 0;
}