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
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

/*조합론적 접근 : 삼각형이 형성됨
  1 / 2 2 / 3 4 3 / 4 6 6 4 / 5 8 9 8 5 / 6 10 10 12 10 6
  F11 = 1, Fij = j * (i - j + 1)
 */

struct info {
	lld val, num, idx;
};


struct cmp {
	bool operator()(info& A, info& B) {
		if (A.val == B.val) return A.num > B.num;
		return A.val > B.val;
	}
};

lld f(lld i, lld j) { return j * (i - j + 1); } //Fij = j * (i - j + 1);
priority_queue<info, vector<info>, cmp> pq; //Fij, num 순

struct segment {
	lld size, l, r, lp, rp;
	void push_left(lld idx) {
		if (l > r) return;
		pq.push({ f(size, lp), l, idx });
		l++, lp++;
	}
	void push_right(lld idx) {
		if (r < l) return;
		pq.push({ f(size, rp), r, idx });
		r--, rp--;
	}
};

int in[50];
vector<segment> v;
int L, N, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L;
	lld before, now;
	before = 0;
	for (int i = 0; i < L; i++) cin >> in[i];
	sort(in, in + L);

	for (int i = 0; i < L; i++) {
		now = in[i];
		if (now - before > 1) v.push_back({ now - before - 1, before + 1, now - 1, 1, now - before - 1 });
		v.push_back({ 1, now, now, 1, 1 });
		before = now;
	}
	cin >> N;
	for (int i = 0; i < v.size(); i++) { v[i].push_left(i); v[i].push_right(i); }
	while (!pq.empty() && cnt < N) {
		info now = pq.top();
		pq.pop();
		cout << now.num << ' ';
		v[now.idx].push_left(now.idx);
		v[now.idx].push_right(now.idx);
		cnt++;
	}
	for (; cnt < N; cnt++) cout << ++now << ' ';

	return 0;
}
