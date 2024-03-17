#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y;
};

bool compare(pos A, pos B) {
	if (A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}

int N;
pos v[100000];

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
	void update(int l, int r, int x, int key) {
		if (l > x || r < x) return;
		if (l == r) val += key;
		else {
			int mid = (l + r) / 2;
			left->update(l, mid, x, key);
			right->update(mid + 1, r, x, key);
			val = left->val + right->val;
		}
	}
	int query(int l, int r, int s, int e) {
		if (s <= l && r <= e) return val;
		if (s > r || l > e) return 0;
		int mid = (l + r) / 2;
		return (left->query(l, mid, s, e) + right->query(mid + 1, r, s, e));
	}
};
segNode* tree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	tree = new segNode(0, 10100);
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> v[i].x >> v[i].y;
			v[i].y += 20;
		}
		sort(v, v + N, compare);
		int i, j, res;
		i = j = res = 0;
		for (; i < N; i++) {
			while (v[j].x - v[i].x <= 10 && j < N) tree->update(0, 10100, v[j].y, 1), j++;
			for (int g = -10; g <= 0; g++) res = max(res, tree->query(0, 10100, v[i].y + g, v[i].y + g + 10));
			tree->update(0, 10100, v[i].y, -1);
		}
		cout << res << '\n';
	}
	return 0;
}
