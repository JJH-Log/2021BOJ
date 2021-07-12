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
	int h;
};

struct cmp {
	bool operator()(pos& A, pos& B) {
		if (A.h == B.h) {
			if (A.x == B.x) return A.y < B.y;
			else return A.x < B.x;
		}
		else return A.h < B.h;
	}
};

vector<vector<int>> v;
vector<vector<int>> w;
priority_queue<pos, vector<pos>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M;
	cin >> N >> M;
	v.resize(N, vector<int>(M, 0));
	w.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> v[i][j];
			pq.push({ i, j, v[i][j] });
		}
	}
	w[0][0] = 1;
	int x, y, dx, dy, h;
	while (!pq.empty()) {
		x = pq.top().x;
		y = pq.top().y;
		h = pq.top().h;
		pq.pop();
		for (i = 0; i < 4; i++) {
			dx = x + "2011"[i] - '1';
			dy = y + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && v[dx][dy] < h) w[dx][dy] += w[x][y];
		}
	}
	cout << w[N - 1][M - 1];
	return 0;
}