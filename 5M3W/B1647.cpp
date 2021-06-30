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
	int d;
};

vector<pos> e;
vector<pair<int, int>> u;

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

	int i, j, N, M, B;
	int p, q;
	int result;
	int a, b, c;
	cin >> N >> M;

	u.resize(N);
	for (i = 0; i < N; i++) u[i] = { i, 1 };

	e.resize(M);
	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		e[i] = { a - 1,b - 1,c };
	}
	sort(e.begin(), e.end(), compare);

	i = 0; result = 0; B = 0;
	while (true) {
		
		p = find(e[i].p);
		q = find(e[i].q);
		if (p == q) i++;
		else {
			result += e[i].d;
			if (B < e[i].d) B = e[i].d;
			if (p > q) swap(p, q);
			u[q].first = p;
			u[p].second += u[q].second;
			u[q].second = 0;
			i++;
		}
		if (u[0].second == N) break;
	}
	cout << result - B;
	return 0;
}