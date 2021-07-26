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

vector<vector<pair<int, int>>> v; //for tree
vector<vector<vector<int>>> w; //0:Ancestor, 1:Max, 2:Min
vector<int> h; //for depth

void init(int P, int X, int depth) {
	int i, t, next, dist;
	vector<int> temp;
	h[X] = depth;
	i = 0; t = 2;
	while (depth >= t) {
		next = w[X][i][0];
		temp = w[next][i];
		temp[1] = max(w[X][i][1], temp[1]);
		temp[2] = min(w[X][i][2], temp[2]);
		w[X].push_back(temp);
		i++, t *= 2;
	}
	for (i = 0; i < v[X].size(); i++) {
		next = v[X][i].first;
		dist = v[X][i].second;
		if (next != P) {
			w[next].push_back({ X,dist,dist });
			init(X, next, depth + 1);
		}
	}
}

pair<int, int> find(int X, int Y) {
	int i, next, tar;
	pair<int, int> result;
	if (X == Y) return { 0, 1000001 };
	if (h[X] < h[Y]) return find(Y, X);
	if (h[X] > h[Y]) {
		tar = w[X].size();
		for (i = 0; i < w[X].size(); i++) {
			if (h[w[X][i][0]] <= h[Y]) {
				tar = i;
				i = w[X].size();
			}
		}
		if (tar) tar--;
		result = find(w[X][tar][0], Y);
		return { max(w[X][tar][1], result.first), min(result.second, w[X][tar][2]) };
	}
	else {
		tar = w[X].size();
		for (i = 0; i < w[X].size(); i++) {
			if (w[X][i][0] == w[Y][i][0]) {
				tar = i;
				i = w[X].size();
			}
		}
		if (tar) tar--;
		result = find(w[X][tar][0], w[Y][tar][0]);
		result = { max(result.first, w[Y][tar][1]), min(result.second, w[Y][tar][2]) };
		return { max(w[X][tar][1], result.first), min(result.second, w[X][tar][2]) };
	}
	return { 0, 1000001 };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	int x, y, d;
	pair<int, int> ans;
	cin >> N;
	v.resize(N + 1);
	w.resize(N + 1);
	h.resize(N + 1);
	for (i = 1; i < N; i++) {
		cin >> x >> y >> d;
		v[x].push_back({ y, d });
		v[y].push_back({ x, d });
	}
	init(0, 1, 0);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		ans = find(x, y);
		if (ans.second == 1000001) ans.second = 0;
		cout << ans.second << ' ' << ans.first << '\n';
	}
	return 0;
}