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


priority_queue<int> pq;
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, x, y, temp, tar;
	cin >> N >> M;
	v.resize(N + 1, vector<int>(1, 0));
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y][0]++;
	}
	for (i = 1; i <= N; i++) {
		if (!v[i][0]) pq.push(-i);
	}
	while (!pq.empty()) {
		temp = -pq.top();
		pq.pop();
		cout << temp << " ";
		for (i = 1; i < v[temp].size(); i++) {
			tar = v[temp][i];
			v[tar][0]--;
			if (!v[tar][0]) pq.push(-tar);
		}
	}
	return 0;
}
