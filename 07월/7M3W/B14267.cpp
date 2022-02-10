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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXLEN 10000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<int> w; //basic idea of lazy propagation?

void dfs(int now) {
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		w[next] += w[now];
		dfs(next);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N, M;
	cin >> N >> M;
	v.resize(N);
	w.resize(N, 0);
	cin >> x;
	for (i = 1; i < N; i++) cin >> x, v[x - 1].push_back(i);
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		w[x - 1] += y;
	}
	dfs(0);
	for (i = 0; i < N; i++) cout << w[i] << ' ';
	return 0;
}