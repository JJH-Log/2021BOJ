#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v; //Floor = -1
vector<vector<int>> w; //for check

int N, K, W;

void track() {
	int i, j, k, x, y, dx, dy, c, cnt;
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < W; j++) {
			if (!w[i][j] && v[i][j]) {
				cnt = 0;
				c = v[i][j];
				w[i][j] = 1, q.push({ i,j }), cnt++;
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					
					q2.push(q.front());
					q.pop();
					for (k = 0; k < 4; k++) {
						dx = x + "2011"[k] - '1';
						dy = y + "1120"[k] - '1';
						if (dx > 0 && dx <= N && dy >= 0 && dy < W) {
							if (!w[dx][dy] && v[dx][dy] == c) {
								w[dx][dy] = 1, q.push({ dx, dy }), cnt++;
							}
						}
					}
				}
				while (!q2.empty()) {
					if (cnt >= K) w[q2.front().first][q2.front().second] = 2;
					q2.pop();
				}
			}
		}
	}
	return;
}

bool boom() {
	int i, j;
	int FLAG = 0;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < W; j++) {
			if (w[i][j] == 2) FLAG = 1, v[i][j] = 0;
		}
	}
	return FLAG;
}

void drop() {
	int i, j, x, y;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < W; j++) {
			if (v[i][j]) {
				x = i;
				y = j;
				while (!v[x - 1][y]) {
					swap(v[x][y], v[x - 1][y]);
					x--;
				}
			}
		}
	}
	return;
}

void print() {
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < W; j++) {
			cout << (char)('0' + v[i][j]);
		}
		cout << '\n';
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int i, j;
	string s;
	cin >> N >> K;
	W = 10;
	v.resize(N + 1, vector<int>(W, 0));
	for (j = 0; j < W; j++) v[0][j] = -1;
	for (i = N; i > 0; i--) {
		cin >> s;
		for (j = 0; j < W; j++) v[i][j] = s[j] - '0';
	}

	while (true) {
		w.clear();
		w.resize(N + 1, vector<int>(W, 0));
		track();
		if (!boom()) break;
		drop();
	}
	print();
	return 0;
}