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

struct info {
	int x;
	int y;
	int c;
};

struct cmp {
	bool operator()(info& A, info& B){
		if (A.c == B.c) {
			if (A.x == B.x) return A.y > B.y;
			else return A.x > B.x;
		}
		else return A.c > B.c;
	}
};

vector<vector<int>> v;
vector<vector<int>> w;
priority_queue<info, vector<info>, cmp> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(501, vector<int>(501, 0));
	w.resize(501, vector<int>(501, 100000));
	int i, j, k, x1, y1, x2, y2, N;
	cin >> N;
	for (k = 0; k < N; k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (i = x1; i <= x2; i++) {
			for (j = y1; j <= y2; j++) {
				v[i][j] = 1;
			}
		}
	}
	cin >> N;
	for (k = 0; k < N; k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (i = x1; i <= x2; i++) {
			for (j = y1; j <= y2; j++) {
				v[i][j] = 9;
			}
		}
	}
	w[0][0] = 0;
	q.push({ 0, 0, 0 });
	int x, y, dx, dy, c;
	while (!q.empty()) {
		x = q.top().x;
		y = q.top().y;
		c = q.top().c;
		q.pop();
		if (w[x][y] == c) {
			for (i = 0; i < 4; i++) {
				dx = x + "2011"[i] - '1';
				dy = y + "1120"[i] - '1';
				if (dx >= 0 && dx < 501 && dy >= 0 && dy < 501 && v[dx][dy] != 9) {
					if (w[dx][dy] > w[x][y] + v[dx][dy]) w[dx][dy] = w[x][y] + v[dx][dy], q.push({ dx, dy, w[x][y] + v[dx][dy] });
				}
			}
		}
	}
	if (w[500][500] == 100000) cout << -1;
	else cout << w[500][500];
	return 0;
}