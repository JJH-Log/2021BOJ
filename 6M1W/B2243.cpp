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

vector<int> tree;

void change(int Node, int l, int r, int tar, int dx) {
	tree[Node] += dx;
	if (l == r) return;
	int mid = (l + r + 1) / 2;
	if (tar < mid) change(2 * Node, l, mid - 1, tar, dx);
	else change(2 * Node + 1, mid, r, tar, dx);
	return;
}

int find(int Node, int l, int r, int idx) {
	tree[Node]--;
	if (l == r) return l;
	int mid = (l + r + 1) / 2;
	if (idx <= tree[2 * Node]) return find(2 * Node, l, mid - 1, idx);
	else return find(2 * Node + 1, mid, r, idx - tree[2 * Node]);
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, A, B, C;
	cin >> N;
	tree.resize(4000000, 0);
	for (i = 0; i < N; i++) {
		cin >> A >> B;
		if (A == 1) cout << find(1, 1, 1000000, B) << '\n'; 
		else{
			cin >> C;
			change(1, 1, 1000000, B, C);
		}
	}
	return 0;
}