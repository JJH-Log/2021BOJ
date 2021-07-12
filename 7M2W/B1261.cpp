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
	bool operator()(pos& A, pos& B){
		if (A.c == B.c) {
			if (A.x == B.x) return A.y > B.y;
			else return A.x > B.x;
		}
		else return A.c > B.c;
	}
};

vector<vector<int>> v;
vector<vector<int>> w;
priority_queue<pos, vector<pos>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, N, M, x, y, c, dx, dy;
	string s;
	cin >> M >> N;
	v.resize(N, vector<int>(M, 0));
	w.resize(N, vector<int>(M, 30000));
	for(i=0;i<N;i++){
		cin >> s;
		for (j = 0; j < M; j++) v[i][j] = s[j] - '0';
	}
	
	w[0][0] = 0;
	pq.push({ 0, 0, 0 });
	while (!pq.empty()) {
		x = pq.top().x;
		y = pq.top().y;
		c = pq.top().c;
		pq.pop();
		if (c == w[x][y]) {
			for (i = 0; i < 4; i++) {
				dx = x + "2011"[i] - '1';
				dy = y + "1120"[i] - '1';
				if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
					if (w[dx][dy] > w[x][y] + v[dx][dy]) w[dx][dy] = w[x][y] + v[dx][dy], pq.push({ dx, dy, w[dx][dy] });
				}
			}
		}
	}
	cout << w[N - 1][M - 1];
	return 0;
}