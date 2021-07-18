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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXLEN 10000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;



vector<vector<int>> v;
vector<vector<int>> w; //visit check
queue<pair<int, int>> q;

map<int, int> m1;
map<pair<int, int>, int> m2;

int N, M;

void dfs(int sx, int sy, int label) {
	w[sx][sy] = label;
	vector<pair<int, int>> blank;
	int cnt = 0;
	q.push({ sx, sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int dx = x + "2011"[i] - '1';
			int dy = y + "1120"[i] - '1';
			if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
				if (blank.size() < 3 && v[dx][dy] == 0 && w[dx][dy] != label) {
					w[dx][dy] = label;
					blank.push_back({ dx, dy });
				}
				if (v[dx][dy] == 2 && w[dx][dy] != label) {
					w[dx][dy] = label;
					q.push({ dx, dy });
				}
			}
		}
	}
	if (blank.size() == 1) {
		int key = blank[0].first * 1000 + blank[0].second;
		if (m1.count(key)) m1[key] += cnt;
		else m1[key] = cnt;
	}
	if (blank.size() == 2) {
		int key1 = blank[0].first * 1000 + blank[0].second;
		int key2 = blank[1].first * 1000 + blank[1].second;
		if (key1 > key2) swap(key1, key2);
		if (m2.count({ key1, key2 })) m2[{key1, key2}] += cnt;
		else m2[{key1, key2}] = cnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, l, temp, key, result;
	cin >> N >> M;
	v.resize(N, vector<int>(M, 0));
	w.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) cin >> v[i][j];
	}

	l = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (v[i][j] == 2 && w[i][j] == 0) dfs(i, j, l++);
		}
	}
	

	int m1Max1, m1Max2;
	m1Max1 = 0, m1Max2 = 0;
	for (auto it = m1.begin(); it != m1.end(); it++) {
		if (it->second > m1Max2) m1Max2 = it->second;
		if (m1Max1 < m1Max2) swap(m1Max1, m1Max2);
	}
	result = m1Max1 + m1Max2;
	for (auto it = m2.begin(); it != m2.end(); it++) {
		temp = it->second;

		key = it->first.first;
		if (m1.count(key)) temp += m1[key];
		key = it->first.second;
		if (m1.count(key)) temp += m1[key];
		result = max(result, temp);
	}
	
	cout << result;
	return 0;
}