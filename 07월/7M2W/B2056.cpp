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

queue<int> q;
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, tar, now, next, result;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) v[i] = { 0, 0, 0 };
	for (i = 0; i < N; i++) {
		cin >> v[i][0]; //0:time, 1:wait, 2:cnt
		cin >> M;
		for (j = 0; j < M; j++) {
			cin >> tar;
			v[tar - 1].push_back(i);
			v[i][2]++;
		}
	}
	for (i = 0; i < N; i++) {
		if (!v[i][2]) q.push(i);
	}
	result = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		result = max(result, v[now][0] + v[now][1]);
		for (i = 3; i < v[now].size(); i++) {
			next = v[now][i];
			v[next][1] = max(v[next][1], v[now][0] + v[now][1]);
			v[next][2]--;
			if (!v[next][2]) q.push(next);
		}
	}
	cout << result;
	return 0;
}