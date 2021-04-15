#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

struct pos {
	int x;
	int y;
	int step;
	bool floor;
	pos(int a, int b, int c, bool d) : x(a), y(b), step(c), floor(d){};
};

vector<vector<char>> v;
vector<vector<vector<bool>>> c;
queue<struct pos> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j, N, M;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int nx, ny;
	string s1;

	cin >> N >> M;
	v.resize(N, vector<char>(M, '0'));
	c.resize(N, vector<vector<bool>>(M, vector<bool>(2, false)));

	for (i = 0; i < N; i++) {
		cin >> s1;
		for (j = 0; j < M; j++) {
			v[i][j] = s1[j];
		}
	}

	q.push(pos(0,0,0,true));
	c[0][0][0] = true;
	int result = -1;
	while (!q.empty()) {
		struct pos temp = q.front();
		q.pop();
		//cout << temp.x << "," << temp.y << "," << temp.floor << endl;
		if ((temp.x == N - 1) && (temp.y == M - 1)) {
			result = temp.step + 1;
			break;
		}
		else {
			for (i = 0; i < 4; i++) {
				nx = temp.x + dx[i];
				ny = temp.y + dy[i];
				if ((nx >= 0) && (nx <= N - 1) && (ny >= 0) && (ny <= M - 1)) {
					if (!c[nx][ny][temp.floor]) {
						if (v[nx][ny] == '0') {
							c[nx][ny][temp.floor] = true;
							q.push(pos(nx, ny, temp.step + 1, temp.floor));
						}
						else if (temp.floor) {
							c[nx][ny][temp.floor] = true;
							q.push(pos(nx, ny, temp.step + 1, false));
						}
					}
				}
			}
		}
	}
	cout << result;
	return 0;
}
