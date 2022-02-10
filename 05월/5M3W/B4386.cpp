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

struct pos {
	int p;
	int q; //p < q
	double d;
};
vector<vector<double>> v;
vector<pos> e;
vector<pair<int, int>> u;

double dist(double dx, double dy) { return sqrt((dx * dx) + (dy * dy)); }

bool compare(pos a, pos b) {
	if (a.d == b.d) return a.p < b.p;
	return a.d < b.d;
}

int find(int target) {
	if (u[target].first == target) return target;
	else return find(u[target].first);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N;
	int p, q;
	double result;
	cin >> N;
	v.resize(N, vector<double>(2, 0));
	u.resize(N);
	for (i = 0; i < N; i++) u[i] = { i, 1 };
	for (i = 0; i < N; i++) cin >> v[i][0] >> v[i][1];
	if (N == 1) {
		cout << 0;
		return 0;
	}
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) e.push_back({ i,j,dist(v[i][0] - v[j][0], v[i][1] - v[j][1])});
	}
	sort(e.begin(), e.end(), compare);
	i = 0; result = 0;
	while (true) {
		p = find(e[i].p);
		q = find(e[i].q);
		if (p == q) i++;
		else {
			result += e[i].d;
			if (p > q) swap(p, q);
			u[q].first = p;
			u[p].second += u[q].second;
			u[q].second = 0;
		}
		if (u[0].second == N) break;
	}
	cout << result;
	return 0;
}