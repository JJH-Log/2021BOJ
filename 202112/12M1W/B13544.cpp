
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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[100001];
int Q, N;

struct segTree {
	segTree* left, * right;
	vector<int> val;
	segTree(int l, int r) {
		if (l == r) val.push_back(v[l]);
		else {
			int mid = (l + r) / 2;
			left = new segTree(l, mid);
			right = new segTree(mid + 1, r);

			int i, j, ll, rr;
			i = j = 0;
			ll = left->val.size();
			rr = right->val.size();

			while (i != ll && j != rr) {
				if (left->val[i] <= right->val[j]) val.push_back(left->val[i++]);
				else  val.push_back(right->val[j++]);
			}
			while (i != ll) val.push_back(left->val[i++]);
			while (j != rr) val.push_back(right->val[j++]);
		}
	}
	int query(int l, int r, int s, int e, int k) {
		if (s > r || l > e) return 0;
		if (s <= l && r <= e) return val.end() - upper_bound(val.begin(), val.end(), k);
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

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> v[i];
	segTree* tree = new segTree(1, N);
	cin >> Q;
	int now_ans;
	int last_ans = 0;
	for (int i = 0; i < Q; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		now_ans = tree->query(1, N, (x ^ last_ans), (y ^ last_ans), (k ^ last_ans));
		cout << now_ans << '\n';
		last_ans = now_ans;
	}


	return 0;
}