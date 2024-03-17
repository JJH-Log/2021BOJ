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

vector<vector<pair<int, int>>> v;
vector<vector<pair<int, int>>> w; //분할 dp를 위한 vector
vector<int> a; //for ant
vector<int> c; //for cost

void dfs(int P, int X, int depth) {
	int i, temp, tar;
	if (depth != 0) w[X].push_back({ P, c[X] - c[P] });
	i = 1;
	while (depth - pow(2, i) >= 0) {
		tar = w[X][i - 1].first;
		w[X].push_back({ w[tar][i - 1].first, w[X][i - 1].second + w[tar][i - 1].second });
		i++;
	}
	for (i = 0; i < v[X].size(); i++) {
		tar = v[X][i].first;
		if (tar != P) {
			c[tar] = c[X] + v[X][i].second;
			dfs(X, tar, depth + 1);
		}
	}
	return;
}

int trace(int X, int E) { //E for energy
	if (X == 1) return 1;
	int i, result;
	result = X;
	for (i = w[X].size() - 1; i >= 0; i--) {
		if (w[X][i].second <= E) {
			result = trace(w[X][i].first, E - w[X][i].second);
			return result;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, d, N;
	cin >> N;
	a.resize(N + 1, -1);
	c.resize(N + 1, -1);
	v.resize(N + 1);
	w.resize(N + 1);
	for (i = 1; i <= N; i++) cin >> a[i];
	for (i = 1; i < N; i++) {
		cin >> x >> y >> d;
		v[x].push_back({ y, d });
		v[y].push_back({ x, d });
	}
	c[1] = 0;
	dfs(0, 1, 0);
	for (i = 1; i <= N; i++) cout << trace(i, a[i]) << '\n';

	return 0;
}