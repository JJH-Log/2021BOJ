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
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

queue<int> q;
vector<vector<int>> v;
vector<int> w; // for check
int N, M;

int isBipartite() {
	int now, next;
	for (int i = 0; i < N; i++) {
		if (w[i] == -1) {
			w[i] = 0;
			q.push(i);
			while (!q.empty()) {
				now = q.front();
				q.pop();
				for (int j = 0; j < v[now].size(); j++) {
					next = v[now][j];
					if (w[next] == w[now]) {
						while (!q.empty()) q.pop();
						return 0;
					}
					else if (w[next] == -1) {
						w[next] = w[now] ^ 1;
						q.push(next);
					}
				}
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, x, y, T;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N >> M;
		v.resize(N);
		w.resize(N, -1);
		for (i = 0; i < M; i++) {
			cin >> x >> y;
			v[x - 1].push_back(y - 1);
			v[y - 1].push_back(x - 1);
		}
		if (isBipartite()) cout << "YES\n";
		else cout << "NO\n";
		v.clear();
		w.clear();
	}

	return 0;
}