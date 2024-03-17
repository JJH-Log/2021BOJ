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
};

bool inRange(int x, int y) { return (x >= 0) && (x < 8) && (y >= 0) && (y < 8); }

int v[8][8];
bool vtd[8][8];
queue<pos> q, q2;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) v[i][j] = (s[j] == '#');
	}
	q.push({ 7, 0 });

	while (true) {
		if (q.empty()) break;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) vtd[i][j] = 0;
		}

		while (!q.empty()) {
			pos now = q.front(); q.pop();
			if (v[now.x][now.y]) continue;
			for (int i = 0; i < 9; i++) {
				int dx = now.x + "020112201"[i] - '1';
				int dy = now.y + "011202021"[i] - '1';
				if (inRange(dx, dy) && !v[dx][dy] && !vtd[dx][dy]) {
					if (dx == 0 && dy == 7) { 
						cout << 1; 
						return 0; //END
					}
					vtd[dx][dy] = 1;
					q2.push({ dx, dy });
				}
			}
		}

		for (int i = 7; i; i--) {
			for (int j = 0; j < 8; j++) v[i][j] = v[i - 1][j];
		}
		for (int j = 0; j < 8; j++) v[0][j] = 0;

		while (!q2.empty()) {
			q.push(q2.front());
			q2.pop();
		}
	}
	cout << 0;
	return 0;
}