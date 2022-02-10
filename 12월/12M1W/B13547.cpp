
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

int N, Q, sqrtN;
vector<int> H;

struct Query {
	int idx, s, e;
	bool operator < (Query& x) {
		if (s / sqrtN == x.s / sqrtN) return e < x.e; 
		return s / sqrtN < x.s / sqrtN;
	}
};

bool opx(int X, int c) {
	if (c == 0) H[X]++;
	else H[X]--;
	return H[X] + c == 1;
}

vector<int> v, ans;
vector<Query> q;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	H.resize(1000001, 0);

	cin >> N;
	sqrtN = sqrt(N);
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> v[i];

	cin >> Q;
	q.resize(Q);
	ans.resize(Q);
	for (int i = 0; i < Q; i++) {
		cin >> q[i].s >> q[i].e;
		q[i].idx = i;
	}
	sort(q.begin(), q.end());

	int cnt, sidx, eidx;

	sidx = q[0].s, eidx = q[0].e, cnt = 0;
	for (int i = sidx; i <= eidx; i++) if (opx(v[i], 0)) cnt++;
	ans[q[0].idx] = cnt;

	for (int i = 1; i < Q; i++) {
		while (eidx < q[i].e) if (opx(v[++eidx], 0)) cnt++;
		while (eidx > q[i].e) if (opx(v[eidx--], 1)) cnt--;
		while (sidx < q[i].s) if (opx(v[sidx++], 1)) cnt--;
		while (sidx > q[i].s) if (opx(v[--sidx], 0)) cnt++;
		ans[q[i].idx] = cnt;
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';



	return 0;
}