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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<pair<int, int>>> v;
vector<vector<int>> w;
vector<pair<int, int>> a; //depth, cost

vector<int> h;
vector<int> c;

void dfs(int P, int X, int depth) {
	int t, i, next, cost;
	t = 2; i = 1;
	while (depth >= t) {
		next = w[X][i - 1];
		w[X].push_back(w[next][i - 1]);
		t *= 2;
		i++;
	}
	for (i = 0; i < v[X].size(); i++) {
		next = v[X][i].first;
		cost = v[X][i].second;
		if (next != P) {
			h[next] = depth + 1;
			c[next] = c[X] + cost;
			w[next].push_back(X);
			dfs(X, next, depth + 1);
		}
	}
	return;
}

int lca(int A, int B) {
	int i, t, result;
	i = 0; t = 1;
	if (A == B) return A;
	if (h[A] < h[B]) return lca(B, A);
	if (h[A] != h[B]) {
		while ((h[A] - h[B]) >= t) i++, t *= 2;
		return lca(w[A][i - 1], B);
	}
	else {
		for (i = 0; i < w[A].size(); i++) {
			if (w[A][i] == w[B][i]) {
				if (!i) return w[A][i];
				else return lca(w[A][i - 1], w[B][i - 1]);
			}
		}
		return lca(w[A][i - 1], w[B][i - 1]);
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i, x, y, d;
	cin >> N;
	v.resize(N + 1);
	w.resize(N + 1);
	h.resize(N + 1, 0);
	c.resize(N + 1, 0);
	for (i = 1; i < N; i++) {
		cin >> x >> y >> d;
		v[x].push_back({ y, d });
		v[y].push_back({ x, d });
	}
	dfs(0, 1, 0);
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		cout << c[x] + c[y] - 2 * c[lca(x, y)] << '\n';
	}
	return 0;
}