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
vector<vector<int>> w;
vector<int> d;
vector<bool> p;

void init(int X, int P, int depth) {
	int tar, i, t;
	d[X] = depth;
	if (depth != 0) w[X].push_back(P);
	i = 0, t = 2;
	while (t <= depth) {
		tar = w[X][i];
		w[X].push_back(w[tar][i]);
		i++;
		t *= 2;
	}
	for (i = 0; i < v[X].size(); i++) {
		tar = v[X][i];
		if(tar != P) init(v[X][i], X, depth + 1);
	}
}

int LCA(int X, int Y) {
	int i, t;
	if (X == Y) return X;
	if (d[X] < d[Y]) return LCA(Y, X);
	else if (d[X] > d[Y]) {
		i = 0; t = 1;
		while (t <= d[X] - d[Y]) i++, t *= 2;
		return LCA(w[X][i - 1], Y);
	}
	else {
		for (i = 0; i < w[X].size(); i++) {
			if (w[X][i] == w[Y][i]) {
				if (!i) return w[X][i];
				else return LCA(w[X][i - 1], w[Y][i - 1]);
			}
		}
		return LCA(w[X][i - 1], w[Y][i - 1]);
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, T, N;
	int i, x, y, root;
	int A, B;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		v.resize(N);
		w.resize(N);
		d.resize(N);
		p.resize(N, false);
		for (i = 0; i < N - 1; i++) {
			cin >> x >> y;
			v[x - 1].push_back(y - 1);
			p[y - 1] = true;
		}
		root = -1;
		for (i = 0; i < N; i++) if (!p[i]) root = i;
		init(root, 0, 0);
		cin >> A >> B;
		cout << LCA(A - 1, B - 1) + 1 << '\n';
		v.clear();
		w.clear();
		d.clear();
		p.clear();
	}
	return 0;
}