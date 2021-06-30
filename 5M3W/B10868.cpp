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

vector<int> v;
vector<int> tree;

int init(int Node, int l, int r) {
	int mid;
	if (l == r) {
		tree[Node] = v[l];
		return tree[Node];
	}
	else {
		mid = (l + r + 1) / 2;
		tree[Node] = min(init(2 * Node, l, mid - 1), init(2 * Node + 1, mid, r));
		return tree[Node];
	}
	return 0;
}

int find(int Node, int l, int r, int x, int y) {
	if (x <= l && r <= y) return tree[Node];
	else if (r < x || y < l) return (int)1e9 + 1;
	else {
		int mid = (l + r + 1) / 2;
		return min(find(2 * Node, l, mid - 1, x, y), find(2 * Node + 1, mid, r, x, y));
	}
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, x, y;
	cin >> N >> M;
	v.resize(N, 0);
	tree.resize(4 * N, (int)1e9 + 1);
	for (i = 0; i < N; i++) cin >> v[i];
	init(1, 0, N - 1);
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		cout << find(1, 0, N - 1, x - 1, y - 1) << '\n';
	}
	return 0;
}
