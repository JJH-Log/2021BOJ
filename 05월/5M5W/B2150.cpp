#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> ans;
vector<vector<int>> v;
vector<int> w; //for visited
stack<int> s;
int dfsn;

int scc(int X) {
	int i, tar, FLAG;
	w[X] = ++dfsn;
	s.push(X);
	FLAG = w[X];
	for (i = 0; i < (int)v[X].size(); i++) {
		tar = v[X][i];
		if (w[tar] == 0) FLAG = min(FLAG, scc(tar));
		else if (w[tar] != -1) FLAG = min(FLAG, w[tar]);
	}
	if (FLAG == w[X]) {
		vector<int> temp;
		while (1) {
			int t = s.top();
			s.pop();
			temp.push_back(t);
			w[t] = -1;
			if (t == X) break;
		}
		ans.push_back(temp);
	}
	return FLAG;
}

bool cmp(vector<int> A, vector<int> B){
	return A[0] < B[0];
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, E;
	int x, y;

	cin >> N >> E;
	v.resize(N + 1);
	w.resize(N + 1, 0);
	for (i = 0; i < E; i++) {
		cin >> x >> y;
		v[x].push_back(y);
	}
	dfsn = 0;
	for (i = 1; i <= N; i++) {
		if (!w[i]) scc(i);
	}
	for (i = 0; i < (int)ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << (int)ans.size() << '\n';
	for (i = 0; i < (int)ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}