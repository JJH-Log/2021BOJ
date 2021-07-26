#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

struct pos {
	int h;
	int x;
	int y;
};

vector<vector<vector<int>>> v;
queue<pos> q;
int mato;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, N, M, H, dh, dx, dy;
	pos temp;
	cin >> N >> M >> H;
	v.resize(H + 2, vector<vector<int>>(M + 2, vector<int>(N + 2, -1)));
	mato = 0;
	for (k = 1; k <= H; k++) {
		for (i = 1; i <= M; i++) {
			for (j = 1; j <= N; j++) {
				cin >> v[k][i][j];
				if (v[k][i][j] == 1) {
					q.push({ k, i ,j });
				}
				else if (v[k][i][j] == 0) mato++;
			}
		}
	}
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (i = 0; i < 6; i++) {
			dh = temp.h + "021111"[i] - '1';
			dx = temp.x + "110211"[i] - '1';
			dy = temp.y + "111102"[i] - '1';
			if (v[dh][dx][dy] == 0) {
				v[dh][dx][dy] = v[temp.h][temp.x][temp.y] + 1;
				q.push({ dh, dx, dy });
				mato--;
			}
		}
	}
	if (mato == 0) cout << v[temp.h][temp.x][temp.y] - 1;
	else cout << "-1";
}

