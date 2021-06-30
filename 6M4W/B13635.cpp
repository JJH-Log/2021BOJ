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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, M, N, dx, dy;
	pair<int, int> now;
	string s;
	cin >> M >> N;
	v.resize(M, vector<int>(N, 0));

	for (i = 0; i < M; i++) {
		cin >> s;
		for (j = 0; j < N; j++) v[i][j] = s[j] - '0';
	}

	for (j = 0; j < N; j++) {
		if (!v[0][j]) {
			v[0][j] = 2;
			q.push({ 0, j });
		}
	}
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (i = 0; i < 4; i++) {
			dx = now.first + "2011"[i] - '1';
			dy = now.second + "1120"[i] - '1';
			if (dx >= 0 && dx < M && dy >= 0 && dy < N) {
				if (!v[dx][dy]) {
					v[dx][dy] = 2;
					q.push({ dx, dy });
				}
			}
		}
	}
	for (j = 0; j < N; j++) {
		if (v[M - 1][j] == 2) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}