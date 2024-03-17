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
vector<int> w;
vector<int> f;
stack<int> s;
int dfsn;
int gnum;

int scc(int X) {
	int i, tar, FLAG;
	w[X] = ++dfsn;
	FLAG = dfsn;
	s.push(X);
	for (i = 0; i < v[X].size(); i++) {
		tar = v[X][i];
		if (!w[tar]) FLAG = min(FLAG, scc(tar));
		else if (!f[tar]) FLAG = min(FLAG, w[tar]);
	}
	if (FLAG == w[X]) {
		gnum++;
		while (true) {
			int t = s.top();
			s.pop();
			f[t] = gnum;
			if (t == X) break;
		}
	}
	return FLAG;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, x, y, result;
	cin >> N >> M;
	v.resize(2 * N + 1); //+N 할것 1~N : N+1~2N
	w.resize(2 * N + 1, 0);
	f.resize(2 * N + 1, 0);
	dfsn = 0;
	gnum = 0;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		v[N - x].push_back(N + y);
		v[N - y].push_back(N + x);
	}

	for (i = 2 * N; i >= 0; i--) {
		if ((i != N) && !w[i]) scc(i);
	}
	result = 1;
	for (i = 1; i <= N; i++) {
		if (f[N + i] == f[N - i]) result = 0, i = N;
	}
	cout << result;
	return 0;
}