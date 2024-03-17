#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
	int x, y, z;
};

int v[30][30][30];
queue<pos> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L, R, C;
	int i, j, k;
	int dx, dy, dz;
	pos now, E;
	bool FLAG;
	string s;
	while (true) {
		cin >> L >> R >> C;
		if (!L) break;
		for (i = 0; i < L; i++) {
			for (j = 0; j < R; j++) {
				cin >> s;
				for (k = 0; k < C; k++) {
					if (s[k] == '#') v[i][j][k] = -1;
					else v[i][j][k] = 0;
					if (s[k] == 'S') v[i][j][k] = 1, q.push({ i,j,k });
					if (s[k] == 'E') E = { i, j, k };
				}
			}
		}
		FLAG = false;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (now.x == E.x && now.y == E.y && now.z == E.z) { FLAG = true;  break; }
			for (i = 0; i < 6; i++) {
				dx = now.x + "201111"[i] - '1';
				dy = now.y + "112011"[i] - '1';
				dz = now.z + "111120"[i] - '1';
				if (dx >= 0 && dx < L && dy >= 0 && dy < R && dz >= 0 && dz < C) {
					if (!v[dx][dy][dz]) {
						v[dx][dy][dz] = v[now.x][now.y][now.z] + 1;
						q.push({ dx,dy,dz });
					}
				}
			}
		}
		if (FLAG) cout << "Escaped in " << v[now.x][now.y][now.z] - 1 << " minute(s).\n";
		else cout << "Trapped!\n";
		q = queue<pos>();
	}
	return 0;
}