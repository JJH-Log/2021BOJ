#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<int> v;
vector<vector<int>> f;
queue<int> q;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, a, b, N, M, result, cnt, temp, ans;
	cin >> N >> M;
	f.resize(N + 1);
	ans = 0;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		f[a].push_back(b);
		f[b].push_back(a);
	}
	result = 600;
	for (i = 1; i <= N; i++) {
		v.clear();
		v.resize(N + 1, 0);
		cnt = 0;
		q.push(i);
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			for (j = 0; j < f[temp].size(); j++) {
				if (f[temp][j] != i && v[f[temp][j]] == 0) {
					v[f[temp][j]] = v[temp] + 1;
					q.push(f[temp][j]);
				}
			}
		}
		for (j = 1; j <= N; j++) cnt += v[j];
		if (cnt < result) {
			result = cnt;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}

