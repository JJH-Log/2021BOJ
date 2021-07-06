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

vector<vector<int>> v; //R,G,B,P,Y, Floor = -1
vector<vector<int>> w; //for check

void track() {
	int i, j, k, x, y, dx, dy, c, cnt;
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	for (i = 1; i < 13; i++) {
		for (j = 0; j < 6; j++) {
			if (!w[i][j] && v[i][j]) {
				cnt = 0;
				w[i][j] = 1;
				c = v[i][j];
				q.push({ i,j }), cnt++;
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					w[x][y] = 1;
					q2.push(q.front());
					q.pop();
					for (k = 0; k < 4; k++) {
						dx = x + "2011"[k] - '1';
						dy = y + "1120"[k] - '1';
						if (dx >= 0 && dx < 13 && dy >= 0 && dy < 6) {
							if (!w[dx][dy] && v[dx][dy] == c) {
								q.push({ dx, dy }), cnt++;
							}
						}
					}
				}
				while (!q2.empty()) {
					if (cnt > 3) w[q2.front().first][q2.front().second] = 2;
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
	for (i = 1; i < 13; i++) {
		for (j = 0; j < 6; j++) {
			if (w[i][j] == 2) FLAG = 1, v[i][j] = 0;
		}
	}
	return FLAG;
}

void drop() {
	int i, j, x, y;
	for (i = 1; i < 13; i++) {
		for (j = 0; j < 6; j++) {
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
	cout << endl;
	for (int i = 12; i > 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (!v[i][j]) cout << '.';
			else cout << (char)v[i][j];
		}
		cout << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, combo;
	string s;
	v.resize(13, vector<int>(6, 0));
	for (j = 0; j < 6; j++) v[0][j] = -1;
	for (i = 12; i > 0; i--) {
		cin >> s;
		for (j = 0; j < 6; j++) {
			if (s[j] != '.') v[i][j] = (int)s[j];
		}
	}

	combo = 0;
	while (true) {
		w.clear();
		w.resize(13, vector<int>(6, 0));
		track();
		if (!boom()) {
			cout << combo;
			return 0;
		}
		drop();
		combo++;
	}
	return 0;
}