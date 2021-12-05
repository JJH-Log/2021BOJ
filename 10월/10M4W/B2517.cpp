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

struct segNode {
	int val;
	segNode* left, * right;
	segNode(int l, int r) :val(0) {
		if (l != r) {
			int mid = (l + r) / 2;
			left = new segNode(l, mid);
			right = new segNode(mid + 1, r);
		}
	}
	void update(int l, int r, int x) {
		if (l <= x && x <= r) {
			if (l == r) val = 1;
			else {
				int mid = (l + r) / 2;
				left->update(l, mid, x);
				right->update(mid + 1, r, x);
				val = left->val + right->val;
			}
		}
	}
	int query(int l, int r, int s, int e) {
		if (s > r || l > e) return 0;
		if (s <= l && r <= e) return val;
		int mid = (l + r) / 2;
		return left->query(l, mid, s, e) + right->query(mid + 1, r, s, e);
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1, pq2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, t; 
	cin >> N;
	segNode *root = new segNode(0, N - 1);
	
	for (int i = 0; i < N; i++) {
		cin >> t;
		pq1.push({ t, i });
	}
	for (int i = 0; i < N; i++) {
		pq2.push({ pq1.top().second, i });
		pq1.pop();
	}
	for (int i = 0; i < N; i++) {
		t = pq2.top().second;
		root->update(0, N - 1, t);
		if (!i) cout << 1 << '\n';
		else cout << i + 1 - root->query(0, N - 1, 0, t - 1) << '\n';
		pq2.pop();
	}
	return 0;
}