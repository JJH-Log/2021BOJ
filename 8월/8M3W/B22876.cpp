#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

pair<lld, lld> selectVal(pair<lld, lld> A, pair<lld, lld> B) {
	if (A.second < B.first) swap(A.second, B.first);
	if (A.first < A.second) swap(A.first, A.second);
	if (A.second < B.second) swap(A.second, B.second);
	if (A.first < A.second) swap(A.first, A.second);
	return A;
}

vector<lld> tx, ty, mx, my;
vector<map<int,lld>> wx, wy;

struct segTree {
	struct segNode {
		int l, r, mid;
		pair<lld, lld> val;
		segNode* left, * right;

		segNode(int l, int r) :l(l), r(r), val({ 0, 0 }) {
			mid = (l + r) / 2;
			if (l != r) {
				left = new segNode(l, mid);
				right = new segNode(mid + 1, r);
			}
		}

		void update(int X, int key) {
			if (l == X && X == r) {
				val.first += key;
				return;
			}
			if (l <= X && X <= r) {
				left->update(X, key);
				right->update(X, key);
				val = selectVal(left->val, right->val);
			}
		}
	};

	segNode* root;
	segTree(int l, int r) { root = new segNode(l, r); }

	void update(int X, int key) { root->update(X, key); }
	lld getSum() { return root->val.first + root->val.second; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, x, y, d;
	lld result = 0;
	segTree* xTree = new segTree(0, 1000000);
	segTree* yTree = new segTree(0, 1000000);
	wx.resize(1000001);
	wy.resize(1000001);
	tx.resize(1000001, 0);
	ty.resize(1000001, 0);
	mx.resize(4, 0);
	my.resize(4, 0);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x >> y >> d;
		xTree->update(x, d);
		yTree->update(y, d);
		tx[x] += d;
		ty[y] += d;
		wx[x][y] = d;
		wy[y][x] = d;
	}
	result = 0;
	for (i = 0; i <= 1000000; i++) {
		if (!wx[i].size()) continue;
		else {
			for (auto& j : wx[i]) yTree->update(j.first, -j.second);
			result = max(result, tx[i] + yTree->getSum());
			for (auto& j : wx[i]) yTree->update(j.first, j.second);
			mx[0] = tx[i];
			sort(mx.begin(), mx.end());
		}
	}
	for (i = 0; i <= 1000000; i++) {
		if (!wy[i].size()) continue;
		else {
			for (auto& j : wy[i]) xTree->update(j.first, -j.second);
			result = max(result, ty[i] + xTree->getSum());
			for (auto& j : wy[i]) xTree->update(j.first, j.second);
			my[0] = ty[i];
			sort(my.begin(), my.end());
		}
	}
	result = max(result, mx[1] + mx[2] + mx[3]);
	result = max(result, my[1] + my[2] + my[3]);
	cout << result;
	return 0;
}