#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;
queue<int> q;
queue<int> result;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt;
	int i, j, N, M, L, temp, before, tar;
	cin >> N >> M;
	v.resize(N + 1, vector<int>(1, 0));
	for (i = 0; i < M; i++) {
		cin >> L;
		before = 0;
		for (j = 0; j < L; j++) {
			cin >> temp;
			if (before) {
				v[before].push_back(temp);
				v[temp][0]++;
			}
			before = temp;
		}
	}
	for (i = 1; i <= N; i++) { if (!v[i][0]) q.push(i); }
	cnt = 0;
	while (!q.empty()) {
		temp = q.front();
		cnt++, result.push(temp);
		q.pop();
		for (i = 1; i < v[temp].size(); i++) {
			tar = v[temp][i];
			v[tar][0] --;
			if (!v[tar][0]) q.push(tar);
		}
	}
	if (cnt != N) cout << 0;
	else {
		while (!result.empty()) {
			cout << result.front() << '\n';
			result.pop();
		}
	}
	return 0;
}
