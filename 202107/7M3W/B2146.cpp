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

vector<vector<pair<int, int>>> v;
queue<pair<int, int>> q;
int N;

bool isNotVisited(pair<int, int> A) {
	return !A.first && !A.second;
}

bool isInBound(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < N;
}

int isContacted(int x, int y) {
	int result = 100000;
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (isInBound(dx, dy) && v[dx][dy].second && v[dx][dy].second != v[x][y].second) result = min(result, v[dx][dy].first);
	}
	return result;
}


void dfs(int x, int y, int label) {
	v[x][y].second = label;
	q.push({ x, y });
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if (isInBound(dx, dy) && isNotVisited(v[dx][dy])) dfs(dx, dy, label);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int label;
	cin >> N;
	v.resize(N, vector<pair<int, int>>(N, { 0, 0 }));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> v[i][j].first;
			v[i][j].first--;
		}
	}

	label = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (isNotVisited(v[i][j])) dfs(i, j, ++label);
		}
	}

	int x, y, dx, dy, cont;
	int result = 100000;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			dx = x + "2011"[i] - '1';
			dy = y + "1120"[i] - '1';
			if (isInBound(dx, dy)) {
				if(!v[dx][dy].second){
					v[dx][dy] = { v[x][y].first + 1, v[x][y].second }, q.push({ dx, dy });
					cont = isContacted(dx, dy);
					if (cont != 100000) result = min(result, v[dx][dy].first + cont);
				}
			}
		}
	}
	cout << result;
	return 0;
}