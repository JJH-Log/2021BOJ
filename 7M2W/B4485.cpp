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

struct pos {
	int x;
	int y;
	int c;
};

struct cmp {
	bool operator()(pos& A, pos& B) {
		if (A.c == B.c) {
			if (A.x == A.x) return A.y > B.y;
			else return A.x > B.x;
		}
		else return A.c > B.c;
	}
};

priority_queue<pos, vector<pos>, cmp> pq;
vector<vector<int>> v;
vector<vector<int>> w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, x, y, dx, dy, c, t;
	t = 1;
	while (true) {
		cin >> N;
		if (!N) break;
		v.resize(N, vector<int>(N, 0));
		w.resize(N, vector<int>(N, 10000));
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> v[i][j];
			}
		}
		w[0][0] = v[0][0];
		pq.push({ 0, 0, w[0][0] });
		while (!pq.empty()) {
			x = pq.top().x;
			y = pq.top().y;
			c = pq.top().c;
			pq.pop();
			if (w[x][y] == c) {
				for (i = 0; i < 4; i++) {
					dx = x + "2011"[i] - '1';
					dy = y + "1120"[i] - '1';
					if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
						if (w[dx][dy] > w[x][y] + v[dx][dy]) w[dx][dy] = w[x][y] + v[dx][dy], pq.push({ dx, dy, w[dx][dy] });
					}
				}

			}
		}
		cout << "Problem " << t << ": " << w[N - 1][N - 1] << '\n';
		t++;
		v.clear();
		w.clear();
	}
	return 0;
}