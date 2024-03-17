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

vector<vector<int>> v;
vector<int> w;

int dfs(int X, int cnt) {
	int i, next, ans;
	if (cnt == 4) return 1;
	w[X] = 1; ans = 0;
	for (i = 0; i < v[X].size(); i++) {
		next = v[X][i];
		if (!w[next]) ans = max(ans, dfs(next, cnt + 1));
	}
	w[X] = 0;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N, M, result;
	cin >> N >> M;
	v.resize(N);
	w.resize(N, 0);
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (i = 0; i < N; i++) {
		if(dfs(i, 0)) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}