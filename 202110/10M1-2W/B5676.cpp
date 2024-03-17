#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct segTree {
	int val;
	segTree* left, * right;
	segTree(int s, int e):val(0){
		if (s != e) {
			int mid = (s + e) / 2;
			left = new segTree(s, mid);
			right = new segTree(mid + 1, e);
		}
	}
	
	void update(int s, int e, int x, int key) {
		if (x < s || x > e) return;
		if (s == e) val = key;
		else {
			int mid = (s + e) / 2;
			left->update(s, mid, x, key);
			right->update(mid + 1, e, x, key);
			val = left->val * right->val;
		}
	}

	int query(int s, int e, int l, int r) {
		if (r < s || e < l) return 1;
		if (l <= s && e <= r) return val;
		else {
			int mid = (s + e) / 2;
			return left->query(s, mid, l, r) * right->query(mid + 1, e, l, r);
		}
	}
};


int ozmo(int t) {
	if (t > 0) return 1;
	if (t < 0) return -1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int t, a, b;
	char q;
	while (true) {
		cin >> N >> M;
		if (cin.eof()) break;

		segTree* root = new segTree(1, N);
		string result = "";
		for (int i = 1; i <= N; i++) {
			cin >> t;
			root->update(1, N, i, ozmo(t));
		}

		for (int i = 0; i < M; i++) {
			cin >> q >> a >> b;
			if (q == 'C') root->update(1, N, a, ozmo(b));
			else {
				t = root->query(1, N, a, b);
				if (t > 0) result += "+";
				else if (t < 0) result += "-";
				else result += "0";
			}
		}
		cout << result << '\n';

	}

	return 0;
}