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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
lld res;
string v[100000];
pair<string, int> w[100000];

struct segNode {
	segNode* left, * right;
	int val;

	segNode(int l, int r) :val(0) {
		if (l != r) {
			int mid = (l + r) / 2;
			left = new segNode(l, mid);
			right = new segNode(mid + 1, r);
		}
	}
	void update(int l, int r, int x, int key) {
		if (x < l || r < x) return;
		if (l == x && r == x) {
			val += key;
			return;
		}
		int mid = (l + r) / 2;
		left->update(l, mid, x, key);
		right->update(mid + 1, r, x, key);
		val = left->val + right->val;
	}

	int query(int l, int r, int s, int e) {
		if (s <= l && r <= e) return val;
		if (s > r || l > e) return 0;
		int mid = (l + r) / 2;
		return left->query(l, mid, s, e) + right->query(mid + 1, r, s, e);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	segNode* tree = new segNode(0, N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	for (int i = 0; i < N; i++) {
		w[i] = { v[i], i };
		reverse(w[i].first.begin(), w[i].first.end());
	}
	sort(w, w + N);
	for (int i = 0; i < N; i++) {
		res += tree->query(0, N, w[i].second + 1, N);
		tree->update(0, N, w[i].second, 1);
	}
	cout << res;

	return 0;
}
