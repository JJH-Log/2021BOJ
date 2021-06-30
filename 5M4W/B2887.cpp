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
	int A;
	int B;
	int D;
};

struct comp {
	bool operator()(info X, info Y) {
		if (X.D == Y.D) {
			if (X.A == Y.A) return X.B > Y.B;
			else return X.A > Y.A;
		}
		else return X.D > Y.D;
	}
};

vector<pair<int, int>> vx;
vector<pair<int, int>> vy;
vector<pair<int, int>> vz;
vector<int> w;
priority_queue<info, vector<info>, comp> pq;

int find(int X) {
	if (X == w[X]) return X;
	else return find(w[X]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long result;
	int i, N, cnt;
	int x, y, z;
	int a, b;
	info temp;
	cin >> N;
	vx.resize(N); vy.resize(N); vz.resize(N);
	w.resize(N);
	for (i = 0; i < N; i++) {
		cin >> x >> y >> z;
		vx[i] = { x, i }; vy[i] = { y, i }; vz[i] = { z, i };
		w[i] = i;
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	sort(vz.begin(), vz.end());

	for (i = 0; i < N - 1; i++) {
		pq.push({ vx[i].second, vx[i + 1].second, vx[i + 1].first - vx[i].first });
		pq.push({ vy[i].second, vy[i + 1].second, vy[i + 1].first - vy[i].first });
		pq.push({ vz[i].second, vz[i + 1].second, vz[i + 1].first - vz[i].first });
	}
	cnt = 1; result = 0;
	while (cnt != N) {
		temp = pq.top();
		pq.pop();
		a = find(temp.A);
		b = find(temp.B);
		if (a != b) {
			if (a > b) swap(a, b);
			w[b] = a;
			result += temp.D;
			cnt++;
		}
	}
	cout << result;
	return 0;
}
