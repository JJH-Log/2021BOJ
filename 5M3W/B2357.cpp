#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

struct info {
	int m;
	int M;
};

vector<int> v;
vector<info> tree;

info init(int Node, int l, int r) {
	int mid;
	info A, B;
	if (l == r) tree[Node] = { v[l], v[l] };
	else {
		mid = (l + r + 1) / 2;
		A = init(2 * Node, l, mid - 1);
		B = init(2 * Node + 1, mid, r);
		tree[Node] = { min(A.m, B.m), max(A.M, B.M) };
	}
	return tree[Node];
}

info find(int Node, int l, int r, int x, int y) {
	info A, B;
	if (x <= l && r <= y) return tree[Node];
	else if (r < x || y < l) return { (int)1e9 + 1, 0 };
	else {
		int mid = (l + r + 1) / 2;
		A = find(2 * Node, l, mid - 1, x, y);
		B = find(2 * Node + 1, mid, r, x, y);
		return { min(A.m, B.m), max(A.M, B.M) };
	}
	return tree[Node];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, x, y;
	info temp;
	cin >> N >> M;
	v.resize(N, 0);
	tree.resize(4 * N, info{(int)1e9 + 1, 0 });
	for (i = 0; i < N; i++) cin >> v[i];
	init(1, 0, N - 1);
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		temp = find(1, 0, N - 1, x - 1, y - 1);
		cout << temp.m << " " << temp.M << '\n';
	}
	return 0;
}
