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

vector<pair<int, int>> v; //time, way
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, cut, i, t;
	cin >> N >> K;
	cut = 0;
	v.resize(100001, { 0,0 });
	q.push(N);
	v[N] = { 1,1 };
	while (!q.empty()) {
		t = q.front();
		q.pop();
		int vt[3] = { t+1,t-1,t*2 };
		for (i = 0; i < 3; i++) {
			if (vt[i] >= 0 && vt[i] <= 100000) {
				if (!v[vt[i]].first) {
					v[vt[i]] = { v[t].first + 1, v[t].second };
					q.push(vt[i]);
				}
				else if (v[vt[i]].first == v[t].first + 1) v[vt[i]].second += v[t].second;
			}
		}
	}
	cout << v[K].first - 1 << "\n" << v[K].second;
	return 0;
}