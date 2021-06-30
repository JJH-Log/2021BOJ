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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<pair<int,int>>> v;
vector<vector<pair<int,int>>> r;
vector<int> w;
vector<int> c;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, S, D;
	int i, j, x, y, d;
	int now, next, cost, cnt;
	cin >> N >> M;
	v.resize(N + 1, vector<pair<int, int>>(1, { 0, 0 }));
	r.resize(N + 1);
	c.resize(N + 1, 0);
	w.resize(N + 1, 0);
	for (i = 0; i < M; i++) {
		cin >> x >> y >> d;
		v[y][0].first++;
		v[x].push_back({ y,d });
	}
	cin >> S >> D;
	q.push(S);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (i = 1; i < v[now].size(); i++) {
			next = v[now][i].first;
			cost = v[now][i].second;
			if (w[next] == w[now] + cost) r[next].push_back({ now, cost });
			else if (w[next] < w[now] + cost) {
				r[next].clear();
				r[next].push_back({ now, cost });
				w[next] = w[now] + cost;
			}
			v[next][0].first--;
			if (!v[next][0].first) q.push(next);
		}
	}
	cnt = 0;
	q.push(D);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (i = 0; i < r[now].size(); i++) {
			next = r[now][i].first;
			cost = r[now][i].second;
			if (w[now] == w[next] + cost) {
				cnt++;
				if (!c[next]) c[next] = 1, q.push(next);
			}
		}
	}
	cout << w[D] << '\n' << cnt;
	return 0;
}