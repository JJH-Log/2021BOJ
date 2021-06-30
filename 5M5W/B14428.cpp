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
using lld = long long;

vector<int> v;
vector<pair<int, int>> tree; //X, idx


pair<int, int> init(int Node, int l, int r) {
	int mid = (l + r) / 2;
	if (l == r) tree[Node] = { v[l], l };
	else tree[Node] = min(init(2 * Node, l, mid), init(2 * Node + 1, mid + 1, r));
	return tree[Node];
}

pair<int, int> ans(int Node, int l, int r, int x, int y) {
	int mid = (l + r) / 2;
	if (y < l || r < x) return { (int)2e9, 100001 };
	else if (x <= l && r <= y) return tree[Node];
	return min(ans(2 * Node, l, mid, x, y), ans(2 * Node + 1, mid + 1, r, x, y));
}

pair<int, int> change(int Node, int l, int r, int tar, int X) {
	int mid = (l + r) / 2;
	if (l == tar && r == tar) tree[Node] = { X, tar };
	else if (l <= tar && tar <= r) {
		tree[Node] = min(change(2 * Node, l, mid, tar, X), change(2 * Node + 1, mid + 1, r, tar, X));
	}
	return tree[Node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, N, M, a, b, c;
	cin >> N;
	v.resize(N);
	tree.resize(4 * N);
	for (i = 0; i < N; i++) cin >> v[i];
	init(1, 0, N - 1);
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 2) cout << ans(1, 0, N - 1, b - 1, c - 1).second + 1<< '\n';
		else change(1, 0, N - 1, b - 1, c);
	}
	return 0;
}