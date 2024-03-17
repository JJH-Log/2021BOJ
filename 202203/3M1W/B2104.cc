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


struct info {
	int a, idx;
	lld S;
};

int v[100011];
int N;
lld res;

struct segNode {
	info val;
	segNode* left, * right;
	segNode(int l, int r){
		if (l == r) val = { v[l],  l, v[l] };
		if (l != r) {
			int mid = (l + r) / 2;
			left = new segNode(l, mid);
			right = new segNode(mid + 1, r);
			if (left->val.a <= right->val.a) {
				val = left->val;
				val.S += right->val.S;
			}
			else {
				val = right->val;
				val.S += left->val.S;
			}
		}
	}
	info getMin(int l, int r, int s, int e) {
		if (s <= l && r <= e) return val;
		if (s > r || l > e) return { (int)1e9, -1, 0 };
		int mid = (l + r) / 2;
		info ll, rr;
		ll = left->getMin(l, mid, s, e);
		rr = right->getMin(mid + 1, r, s, e);
		if (ll.a <= rr.a) return {ll.a, ll.idx, ll.S + rr.S};
		else return { rr.a, rr.idx, ll.S + rr.S };
	}
	lld solve(int l, int r, int s, int e) {
		if (s > e) return 0;
		if (s == e) return (lld)v[s] * v[s];
		info tmp = getMin(l, r, s, e);
		lld ans = (lld)tmp.a * tmp.S;
		ans = max(ans, solve(l, r, s, tmp.idx - 1));
		ans = max(ans, solve(l, r, tmp.idx + 1, e));
		return ans;
	}
};

segNode* tree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> v[i];
	tree = new segNode(1, N);
	cout << tree->solve(1, N, 1, N);

	return 0;
}
