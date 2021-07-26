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
#define MOD 10007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<int>> w; //분할 dp를 위한 vector
vector<int> d; //for depth

void dfs(int P, int X, int depth) {
	int i, t, tar;
	d[X] = depth;
	if (depth != 0) w[X].push_back(P);
	i = 1; t = 2;
	while (depth >= t) {
		tar = w[X][i - 1];
		w[X].push_back(w[tar][i - 1]);
		i++;
		t *= 2;
	}
	for (i = 0; i < v[X].size(); i++) {
		tar = v[X][i];
		if (tar != P) {
			dfs(X, tar, depth + 1);
		}
	}
	return;
}

int lca(int X, int Y) {
	int i, t, result;
	result = 0;
	if (X == Y) return X;
	if (d[X] > d[Y]) {
		i = 0; t = 1;
		while (d[X] - d[Y]  >= t) i++, t *= 2;
		return lca(w[X][i - 1], Y);
	}
	else {
		for (i = 0; i < w[X].size(); i++) {
			if (w[X][i] == w[Y][i]) {
				if (!i) return w[X][i];
				else return lca(w[X][i - 1], w[Y][i - 1]);
			}
		}
		return lca(w[X][i - 1], w[Y][i - 1]);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N, M;
	cin >> N;
	d.resize(N + 1, -1);
	v.resize(N + 1);
	w.resize(N + 1);
	for (i = 1; i < N; i++) {
		cin >> x >> y;
		v[x].push_back( y );
		v[y].push_back( x );
	}
	dfs(0, 1, 0);
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		if (d[x] < d[y]) swap(x, y);
		cout << lca(x, y) << '\n';
	}
	return 0;
}