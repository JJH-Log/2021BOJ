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

struct cmp {
	bool operator()(pair<lld, lld>&a, pair<lld, lld>&b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};

vector<vector<pair<int, int>>> v;
vector<map<int, int>> w;
vector<map<int, int>> ww;
vector<lld> r;
vector<int> c;
queue<int> q;
priority_queue<pair<lld, lld>, vector<pair<lld, lld>>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, S, D;
	int i, x, y, d;
	int next, cost, now;
	pair<int, int> temp;
	while (true) {
		cin >> N >> M;
		if (!N && !M) break;
		cin >> S >> D;

		v.resize(N);
		w.resize(N);
		ww.resize(N);
		c.resize(N, 1);
		r.resize(N, 1e11);

		for (i = 0; i < M; i++) {
			cin >> x >> y >> d;
			v[x].push_back({ y, d });
		}
		r[S] = 0;
		pq.push({ r[S], S });
		while (!pq.empty()) {
			now = pq.top().second;
			if (r[now] == pq.top().first) {
				for (i = 0; i < v[now].size(); i++) {
					next = v[now][i].first;
					cost = v[now][i].second;
					if (r[next] == r[now] + cost) w[next][now] = 1;
					else if (r[next] > r[now] + cost) {
						w[next].clear();
						w[next][now] = 1;
						r[next] = r[now] + cost;
						pq.push({ r[next], next });
					}
				}

			}
			pq.pop();
		}
		
		q.push(D);
		c[D] = 0;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			for (auto it = w[now].begin(); it != w[now].end(); it++) {
				next = it->first;
				ww[next][now] = 1;
				if (c[next]) {
					c[next] = 0;
					q.push(next);
				}
			}
		}

		r.clear();
		r.resize(N, 1e11);
		r[S] = 0;
		pq.push({ r[S], S });
		while (!pq.empty()) {
			now = pq.top().second;
			if (r[now] == pq.top().first) {
				for (i = 0; i < v[now].size(); i++) {
					next = v[now][i].first;
					cost = v[now][i].second;
					if (!ww[now].count(next)) {
						if (r[next] > r[now] + cost) {
							r[next] = r[now] + cost;
							pq.push({ r[next], next });
						}
					}
				}
			}
			pq.pop();
		}
		if (r[D] == 1e11) cout << -1 << '\n';
		else cout << r[D] << endl;
		v.clear();
		w.clear();
		ww.clear();
		r.clear();
		c.clear();
	}
	return 0;
}