#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<char>> v;
vector<vector<bool>> w;
vector<queue<pair<int, int>>> wait;
vector<int> key;
queue<pair<int, int>> q;

void mark(int x, int y) {
	if(v[x][y] != '.') v[x][y] = '.';
	w[x][y] = false;
	q.push({ x, y });
}

void unlock(char c) {
	if (c == '0') return;
	int tar = c - 'a';
	int x, y;
	key[tar] = 1;
	while (!wait[tar].empty()) {
		x = wait[tar].front().first;
		y = wait[tar].front().second;
		wait[tar].pop();
		mark(x, y);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, T, i, j, N, M, result;
	int x, y, dx, dy;
	string s;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N >> M;
		v.resize(N + 2, vector<char>(M + 2, '.'));
		w.resize(N + 2, vector<bool>(M + 2, true));
		key.resize(26, 0);
		wait.resize(26);
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) cin >> v[i][j];
		}
		cin >> s;
		if (s != "0") {
			for (i = 0; i < s.size(); i++) key[s[i] - 'a'] = 1;
		}
		
		mark(0, 0); result = 0;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (i = 0; i < 4; i++) {
				dx = x + "2011"[i] - '1';
				dy = y + "1120"[i] - '1';
				if (dx >= 0 && dx <= (N + 1) && dy >= 0 && dy <= (M + 1) && w[dx][dy]) {
					if (v[dx][dy] == '*');
					else if (v[dx][dy] >= 'A' && v[dx][dy] <= 'Z') {
						if (key[v[dx][dy] - 'A']) mark(dx, dy);
						else {
							w[dx][dy] = false;
							wait[v[dx][dy] - 'A'].push({ dx, dy });
						}
					}
					else {
						if (v[dx][dy] == '$') result++;
						if (v[dx][dy] >= 'a' && v[dx][dy] <= 'z') unlock(v[dx][dy]);
						mark(dx, dy);
					}
				}
			}
		}
		cout << result << '\n';
		v.clear();
		w.clear();
		key.clear();
		wait.clear();
	}


	return 0;
}
