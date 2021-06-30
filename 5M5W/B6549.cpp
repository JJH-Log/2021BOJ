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

lld answer(int Node, int l, int r, int x1, int x2) {
	if (x1 > x2) return -1;
	if (x1 == x2) return v[x1];
	pair<int, int> temp = ans(Node, l, r, x1, x2);
	lld result = temp.first * ((lld)x2 - x1 + 1);
	result = max(result, answer(Node, l, r, x1, temp.second - 1));
	result = max(result, answer(Node, l, r, temp.second + 1, x2));
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M;
	pair<int, int> temp;

	while (true) {
		cin >> N;
		if (!N) break;
		v.clear();
		tree.clear();
		v.resize(N);
		tree.resize(4 * N);
		for (i = 0; i < N; i++) cin >> v[i];
		init(1, 0, N - 1);
		cout << answer(1, 0, N - 1, 0, N - 1) << '\n';
	}
	return 0;
}