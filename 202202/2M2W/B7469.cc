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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[100001];
int N, Q;

struct segNode {
	vector<int> val;
	segNode* left, * right;
	segNode(int l, int r) {
		if (l != r) {
			int mid = (l + r) / 2;
			left = new segNode(l, mid);
			right = new segNode(mid + 1, r);
			int i, j, rr, ll;
			ll = left->val.size();
			rr = right->val.size();
			i = j = 0;
			while (i < ll && j < rr) {
				if (left->val[i] <= right->val[j]) val.push_back(left->val[i++]);
				else val.push_back(right->val[j++]);
			}
			while(i < ll) val.push_back(left->val[i++]);
			while (j < rr) val.push_back(right->val[j++]);
		}
		else val.push_back(v[l]);
	}
	int query(int l, int r, int s, int e, int k) {
		if (s > r || l > e) return 0;
		if (s <= l && r <= e) return upper_bound(val.begin(), val.end(), k) - val.begin();
		else {
			int mid = (l + r) / 2;
			return left->query(l, mid, s, e, k) + right->query(mid + 1, r, s, e, k);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> v[i];
	segNode* root = new segNode(1, N);
	for (int i = 0; i < Q; i++) {
		int s, e, k;
		cin >> s >> e >> k;
		int l, r, mid, ans;
		l = -1e9, r = 1e9;
		while (l + 1 < r) {
			mid = (l + r) / 2;
			ans = root->query(1, N, s, e, mid);
			if (ans < k) l = mid + 1;
			else r = mid;
		}
		if (root->query(1, N, s, e, l) == k) cout << l << '\n';
		else cout << r << '\n';
	}

	return 0;
}
