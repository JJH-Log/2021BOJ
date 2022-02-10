#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

struct info {
	int l; //for length
	int t; //for type
	int n; //for idx
};

struct cmp {
	bool operator()(info A, info B) {
		if (A.l == B.l) {
			if (A.t == B.t) return A.n > B.n;
			else return A.t > B.t;
		}
		else return A.l > B.l;
	}
};

vector<pair<int,int>> v;
vector<int> w;
priority_queue<info, vector<info>, cmp> pq; // 1: o, 2: h + d

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, x, y, d, now, cnt, result;
	info X;
	pair<int, int> temp;
	cin >> N;
	v.resize(N);
	w.resize(N, 0);
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		if (x > y) swap(x, y);
		v[i] = { x, y };
	}
	sort(v.begin(), v.end());
	cin >> d;
	for (i = 0; i < N; i++) {
		pq.push({ v[i].first + d, 2, i });
		pq.push({ v[i].second, 1, i });
	}
	now = 0;
	cnt = 0;
	result = 0;
	while (!pq.empty()) {
		X = pq.top();
		pq.pop();
		//cout << X.l << " " << X.t << " " << X.n << " ";
		if (X.t == 1) {
			if (X.n >= now) cnt++, w[X.n]++;
		}
		else {
			result = max(result, cnt);
			if (w[X.n]) cnt--;
			now++;
		}
		//cout << now << " " << cnt << endl;
	}
	cout << result;
	return 0;
}
