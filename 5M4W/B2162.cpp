#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<pair<int, int>>> v;
vector<vector<int>> w;

int find(int X) {
	if (X == w[X][0]) return X;
	else return find(w[X][0]);
}

int outer(pair<int, int> a, pair<int, int> b) {
	long long r = (long long)b.second * a.first - (long long)a.second * b.first;
	if (r > 0) return 1; //cw
	if (r < 0) return -1; //ccw
	return 0; //parallel
}

pair<int, int> dxy(pair<int, int> a, pair<int, int>b) {
	return { b.second - a.second, b.first - a.first };
}

int isIntersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int ab = outer(dxy(a, b), dxy(a, c)) * outer(dxy(a, b), dxy(a, d));
	int cd = outer(dxy(c, d), dxy(c, a)) * outer(dxy(c, d), dxy(c, b));
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, x, y, cnt, M;
	cin >> N;
	w.resize(N, vector<int>(2, 1));
	v.resize(N, vector<pair<int, int>>(2, { 0,0 }));
	for (i = 0; i < N; i++) {
		w[i][0] = i;
		cin >> v[i][0].first >> v[i][0].second >> v[i][1].first >> v[i][1].second;
	}
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			x = find(i);
			y = find(j);
			if (x != y) {
				if (isIntersect(v[i][0], v[i][1], v[j][0], v[j][1])) {
					if (x > y) swap(x, y);
					w[y][0] = x;
					w[x][1] += w[y][1];
					w[y][1] = 0;
				}
			}
		}
	}
	M = 0; cnt = 0;
	for (i = 0; i < N; i++) {
		if (w[i][0] == i) {
			cnt++;
			M = max(M, w[i][1]);
		}
	}
	cout << cnt << '\n' << M;
	return 0;
}
