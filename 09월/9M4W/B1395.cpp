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
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct segNode {
	int val;
	bool lazy;
	segNode* left, * right;
	segNode(int s, int e) :val(0), lazy(false) {
		if (s != e) {
			int mid = (s + e) / 2;
			left = new segNode(s, mid);
			right = new segNode(mid + 1, e);
		}
	}
	void update(int s, int e, int l, int r) {
		
		if (e < l || r < s) return;
		else if (l <= s && e <= r) {
			lazy ^= 1;
			val = (e - s + 1) - val;
		}
		else {
			if (!lazy) {
				int mid = (s + e) / 2;
				left->update(s, mid, l, r);
				right->update(mid + 1, e, l, r);
				val = left->val + right->val;
			}
			else {
				lazy = 0;
				if (s < l) this->update(s, e, s, l - 1);
				if (r < e) this->update(s, e, r + 1, e);
			}
		}
	}
	int query(int s, int e, int l, int r) {
		if (e < l || r < s) return 0;
		else if (l <= s && e <= r) return val;
		else {
			int mid = (s + e) / 2;
			if (lazy) {
				lazy = 0;
				left->update(s, mid, s, mid);
				right->update(mid + 1, e, mid + 1, e);
				val = left->val + right->val;
			}
			return left->query(s, mid, l, r) + right->query(mid + 1, e, l, r);
		}
	}
};



int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int o, s, t;
	cin >> N >> M;
	segNode* tree = new segNode(1, N);
	for (int i = 0; i < M; i++) {
		cin >> o >> s >> t;
		if (!o) tree->update(1, N, min(s, t), max(s, t));
		else cout << tree->query(1, N, min(s, t), max(s, t)) << '\n';
	}

	return 0;
}