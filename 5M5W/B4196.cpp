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

vector<vector<int>> v;
vector<vector<int>> g; //for grouping scc
vector<int> w;
vector<int> f;
stack<int> s;
int dfsn, gnum;

int scc(int X) {
	int i, tar, FLAG;
	w[X] = ++dfsn;
	s.push(X);
	FLAG = w[X];
	for (i = 0; i < v[X].size(); i++) {
		tar = v[X][i];
		if (!w[tar]) FLAG = min(FLAG, scc(tar));
		else if (!f[tar]) FLAG = min(FLAG, w[tar]);
		
		if (f[tar]) g[f[tar]][0] = 1;
	}
	if (FLAG == w[X]) {
		while (true) {
			int t = s.top();
			s.pop();
			f[t] = gnum;
			if (t == X) break;
		}
		gnum++;
		g.push_back({ 0 });
	}
	return FLAG;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, T, N, M, x, y, result;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N >> M;
		v.resize(N + 1);
		w.resize(N + 1, 0);
		f.resize(N + 1, 0);
		dfsn = 0;
		gnum = 1;
		result = 0;
		g.push_back({ 0 }); //for dummy
		g.push_back({ 0 }); //for gnum == 1
		for (i = 0; i < M; i++) {
			cin >> x >> y;
			v[x].push_back(y);
		}
		for (i = 1; i <= N; i++) {
			if (!w[i]) scc(i);
		}
		for (i = 1; i < g.size(); i++) {
			if(!g[i][0]) result++;
		}
		cout << result - 1 << '\n';
		v.clear();
		w.clear();
		f.clear();
		g.clear();
	}
	return 0;
}