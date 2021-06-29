#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

struct pos {
	int x;
	int y;
	int d;
};

struct cmp {
	bool operator()(pos& a, pos& b) {
		if (a.d == b.d) {
			if (a.x == b.x) return a.y > b.y;
			return a.x > b.x;
		}
		return a.d > b.d;
	}
};

vector<vector<int>> v;
vector<vector<int>> c;
priority_queue<pos, vector<pos>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, dx, dy, N, FLAG, size, fish, result;
	pos temp;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> v[i][j];
			if (v[i][j] == 9) pq.push({ i,j,0 }), v[i][j] = 0;
		}
	}
	size = 2; fish = 0; result = 0;
	while (true) {
		c.clear();
		c.resize(N, vector<int>(N, 1));
		FLAG = 1;
		while (FLAG && !pq.empty()) {
			temp = pq.top();
			pq.pop();
			if (v[temp.x][temp.y] > 0 && v[temp.x][temp.y] < size) FLAG = 0;
			else {
				for (i = 0; i < 4; i++) {
					dx = temp.x + "0112"[i] - '1';
					dy = temp.y + "1021"[i] - '1';
					if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
						if (c[dx][dy] && (v[dx][dy] <= size)) {
							pq.push({ dx, dy, temp.d + 1 });
							c[dx][dy] = 0;
						}
					}
				}
			}
		}
		if (FLAG) break; //finish
		else {
			v[temp.x][temp.y] = 0;
			result += temp.d;
			fish++;
			if (size == fish) size++, fish = 0;
			while (!pq.empty()) pq.pop();
			pq.push({ temp.x, temp.y, 0 });
		}
	}
	cout << result;
	return 0;
}