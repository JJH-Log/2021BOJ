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

vector<vector<int>> v;
vector<int> vv;
queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, x, y, temp;
	cin >> N;
	v.resize(N + 1, vector<int>());
	vv.resize(N + 1, 0);
	for (i = 1; i < N; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(1);
	vv[1] = 1;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (i = 0; i < v[temp].size(); i++) {
			if (!vv[v[temp][i]]) vv[v[temp][i]] = temp, q.push(v[temp][i]);
		}
	}
	for (i = 2; i <= N; i++) cout << vv[i] << "\n";
}