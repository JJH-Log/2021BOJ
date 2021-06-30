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

vector<lld> v;
vector<lld> tree;


lld init(int Node, int l, int r) {
	int mid = (l + r) / 2;
	if (l == r) tree[Node] = v[l];
	else tree[Node] = init(2 * Node, l, mid) + init(2 * Node + 1, mid + 1, r);
	return tree[Node];
}

lld ans(int Node, int l, int r, int x, int y) {
	int mid = (l + r) / 2;
	if (y < l || r < x) return 0;
	else if (x <= l && r <= y) return tree[Node];
	return ans(2 * Node, l, mid, x, y) + ans(2 * Node + 1, mid + 1, r, x, y);
}

lld change(int Node, int l, int r, int tar, lld X) {
	int mid = (l + r) / 2;
	lld Y;
	if (l == tar && r == tar) {
		Y = X - tree[Node];
		tree[Node] = X;
	}
	else if (l <= tar && tar <= r) {
		Y = change(2 * Node, l, mid, tar, X) + change(2 * Node + 1, mid + 1, r, tar, X);
		tree[Node] += Y;
	}
	else Y = 0;
	return Y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, N, M, K, a, b;
	lld c;
	cin >> N >> M >> K;
	v.resize(N);
	tree.resize(4 * N);
	for (i = 0; i < N; i++) cin >> v[i];
	init(1, 0, N - 1);
	for (i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 2) cout << ans(1, 0, N - 1, b - 1, c - 1) << '\n';
		else change(1, 0, N - 1, b - 1, c);
	}
	return 0;
}