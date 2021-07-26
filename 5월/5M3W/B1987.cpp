#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;


vector<string> v;
vector<int> m;
int R, C, result;

void ans(int x, int y, int cnt) {
	result = max(result, cnt);
	int dx, dy;
	m[v[x][y] - 'A'] = 0;
	for (int i = 0; i < 4; i++) {
		dx = x + "2011"[i] - '1';
		dy = y + "1120"[i] - '1';
		if (dx >= 0 && dx < R && dy >= 0 && dy < C) {
			if (m[v[dx][dy] - 'A']) ans(dx, dy, cnt + 1);
		}
	}
	m[v[x][y] - 'A'] = 1;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	cin >> R >> C;
	v.resize(R);
	m.resize(26, 1);
	for (i = 0; i < R; i++) cin >> v[i];
	result = 0;
	ans(0, 0, 1);
	cout << result;
	return 0;
}