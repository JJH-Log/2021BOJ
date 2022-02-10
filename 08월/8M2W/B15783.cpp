#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> w;
vector<vector<int>> gw;
vector<int> dn;
vector<int> gn;
int dfsn, grn;
stack<int> s;

int dfs(int now) {
	int ans, FLAG;
	dn[now] = ++dfsn;
	FLAG = dn[now];
	s.push(now);
	for (auto& next : w[now]) {
		if (gn[next]) continue;
		if (!dn[next]) ans = dfs(next);
		else ans = dn[next];
		FLAG = min(FLAG, ans);
	}
	if (FLAG == dn[now]) {
		int t;
		vector<int> temp;
		grn++;
		temp.push_back(0);
		while (true) {
			t = s.top();
			s.pop();
			gn[t] = grn;
			temp.push_back(t);
			if (t == now) break;
		}
		gw.push_back(temp);
	}
	return FLAG;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N, M;
	cin >> N >> M;
	w.resize(N);
	dn.resize(N, 0);
	gn.resize(N, 0);
	gw.push_back(vector<int>()); //dummy
	dfsn = grn = 0;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		w[x].push_back(y);
	}
	for (i = 0; i < N; i++) if (!gn[i]) dfs(i);

	for (int now = 0; now < N; now++) {
		for (auto& next : w[now]) {
			if (gn[now] != gn[next]) gw[gn[next]][0]++;
		}
	}

	int result = 0;
	for (i = 1; i < gw.size(); i++) if (!gw[i][0]) result++;
	cout << result;


	return 0;
}