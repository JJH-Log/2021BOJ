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

struct segTree {
	segTree* left, * right;
	int cnt, val;
	segTree() :left(nullptr), right(nullptr), cnt(0), val(0) {}
	void init(int s, int e) {
		if (s != e) {
			int mid = (s + e) / 2;
			left = new segTree();
			right = new segTree();
			left->init(s, mid);
			right->init(mid + 1, e);
		}
	}
	void update(int s, int e, int l, int r, int key) {
		if (r < s || e < l) return;
		if (l <= s && e <= r) cnt += key;
		else {
			int mid = (s + e) / 2;
			left->update(s, mid, l, r, key);
			right->update(mid + 1, e, l, r, key);
		}
		if (cnt) val = e - s + 1;
		else if (s == e) val = 0;
		else val = left->val + right->val;
	}
};

struct pos {
	int x, y1, y2, key;
};

bool compare(pos A, pos B) { return A.x < B.x; }
vector<pos> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(2);
	int N;
	double x1, y1, x2, y2;
	segTree* root = new segTree();
	root->init(1, 20000);
	cin >> N;

	v.resize(2 * N);
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		v[2 * i] = { (int)(10 * (x1 + 0.001)), (int)(10 * (y1 + 0.001)) + 1, (int)(10 * (y1 + y2 + 0.001)), 1 };
		v[2 * i + 1] = { (int)(10 * (x1 + x2 + 0.001)),(int)(10 * (y1 + 0.001)) + 1, (int)(10 * (y1 + y2 + 0.001)), -1 };
	}
	sort(v.begin(), v.end(), compare);
	root->update(1, 20000, v[0].y1, v[0].y2, v[0].key);
	lld result = 0;
	for (int i = 1; i < 2 * N; i++) {
		result += (lld)root->val * (v[i].x - v[i - 1].x);
		root->update(1, 20000, v[i].y1, v[i].y2, v[i].key);
	}

	if (result % 100) cout << (double)result / 100;
	else cout << result / 100;

	return 0;
}