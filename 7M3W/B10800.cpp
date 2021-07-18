#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
#define INT_MIN -2147483647
#define INT_MAX 2147483647
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

struct info {
	int c;
	int s;
	int idx;
};

struct cmp {
	bool operator()(info& A, info& B) {
		if (A.s == B.s) {
			if (A.c == B.c) return A.idx > B.idx;
			return A.c > B.c;
		}
		return A.s > B.s;
	}
};

vector<int> v;
vector<int> w; //0 : 크기가 작은 공들 누적합 , 크기가 같은 공들
int N;

priority_queue<info, vector<info>, cmp> pq;
queue<pair<int, int>> q; //color : size

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N, 0);

	int i, ni, ns, nc, bs;
	int maxColor = 0;
	lld total;
	total = 0;

	for (i = 0; i < N; i++) {
		cin >> nc >> ns;
		maxColor = max(maxColor, nc);
		pq.push({ nc - 1 , ns, i });
	}
	w.resize(maxColor, 0);
	bs = -1;

	while (!pq.empty()) {
		nc = pq.top().c;
		ns = pq.top().s;
		ni = pq.top().idx;
		pq.pop();

		if (ns != bs) {
			while (!q.empty()) {
				w[q.front().first] += q.front().second;
				total += q.front().second;
				q.pop();
			}
		}
		q.push({ nc, ns });	
		v[ni] = total - w[nc];
		bs = ns;
	}
	for (i = 0; i < N; i++) cout << v[i] << '\n';
	return 0;
}