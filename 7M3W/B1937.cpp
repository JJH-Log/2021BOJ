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

vector<vector<int>> v;
vector<vector<int>> w;
vector<int> day;
queue<int> q;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, result;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	w.resize(N * N, vector<int>(1, 0));
	day.resize(N * N, 0);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) cin >> v[i][j];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < 4; k++) {
				int dx = i + "2011"[k] - '1';
				int dy = j + "1120"[k] - '1';
				if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
					if (v[i][j] < v[dx][dy]) {
						w[i * N + j].push_back(dx * N + dy);
						w[dx * N + dy][0]++;
					}
				}
			}
		}
	}

	for (i = 0; i < N * N; i++) if (!w[i][0]) day[i] = 1, q.push(i);
	result = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 1; i < w[now].size(); i++) {
			int next = w[now][i];
			day[next] = max(day[next], day[now] + 1);
			result = max(result, day[next]);
			w[next][0]--;
			if (!w[next][0]) q.push(next);
		}
	}
	cout << result;

	return 0;
}