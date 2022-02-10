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

int N, M;
vector<string> v;
map<string, int> m;
queue<string> q;

string scan() {
	int i, j;
	string r = "0000";
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (v[i][j] == 'R') {
				v[i][j] = '.';
				r[0] = i + '0'; r[1] = j + '0';
			}
			if (v[i][j] == 'B') {
				v[i][j] = '.';
				r[2] = i + '0'; r[3] = j + '0';
			}
		}
	}
	return r;
}

string move(int dx, int dy, string s) {
	int rx, ry, bx, by;
	string result;
	rx = s[0] - '0';
	ry = s[1] - '0';
	bx = s[2] - '0';
	by = s[3] - '0';
	v[rx][ry] = 'R';
	v[bx][by] = 'B';
	while (true) {
		if (v[rx + dx][ry + dy] == '#' || v[rx + dx][ry + dy] == 'B') break;
		else if (v[rx + dx][ry + dy] == 'O') {
			v[rx][ry] = '.';
			v[0][0] = 'R';
			break;
		}
		else {
			v[rx][ry] = '.';
			v[rx + dx][ry + dy] = 'R';
			rx += dx; ry += dy;
		}
	}
	while (true) {
		if (v[bx + dx][by + dy] == '#' || v[bx + dx][by + dy] == 'R') break;
		else if (v[bx + dx][by + dy] == 'O') {
			v[bx][by] = '.';
			v[0][M - 1] = 'B';
			break;
		}
		else {
			v[bx][by] = '.';
			v[bx + dx][by + dy] = 'B';
			bx += dx; by += dy;
		}
	}
	while (true) {
		if (v[0][0] == 'R') break;
		if (v[rx + dx][ry + dy] == '#' || v[rx + dx][ry + dy] == 'B') break;
		else if (v[rx + dx][ry + dy] == 'O') {
			v[rx][ry] = '.';
			v[0][0] = 'R';
			break;
		}
		else {
			v[rx][ry] = '.';
			v[rx + dx][ry + dy] = 'R';
			rx += dx; ry += dy;
		}
	}
	result = scan();
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, result;
	string n, pos, dpos;
	cin >> N >> M;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i];
	n = scan();
	m[n] = 0;
	q.push(n);
	result = -1;
	while (!q.empty() && result == -1) {
		pos = q.front();
		q.pop();
		if (m[pos] <= 9) {
			for (i = 0; i < 4; i++) {
				dpos = move("2011"[i] - '1', "1120"[i] - '1', pos);
				if (dpos[0] == '0' && dpos[2] != '0') result = m[pos] + 1;
				if (dpos[0] != '0' && dpos[2] != '0') {
					if (!m.count(dpos)) {
						m[dpos] = m[pos] + 1;
						//cout << dpos << " " << m[dpos] << endl;
						q.push(dpos);
					}
				}
			}
		}
	}
	cout << result;
	return 0;
}
