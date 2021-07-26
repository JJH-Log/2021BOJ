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

vector<int> v;
vector<int> total;
vector<vector<int>> w;
queue<int> q;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int i, temp;
	cin >> N;
	v.resize(N);
	total.resize(N);
	w.resize(N, vector<int>(1, 0));

	for (i = 0; i < N; i++) {
		cin >> v[i];
		while (true) {
			cin >> temp;
			if (temp == -1) break;
			w[temp - 1].push_back(i);
			w[i][0]++;
		}
	}

	for (i = 0; i < N; i++) if (!w[i][0]) total[i] = v[i], q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 1; i < w[now].size(); i++) {
			int next = w[now][i];
			total[next] = max(total[next], total[now] + v[next]);
			w[next][0]--;
			if (!w[next][0]) q.push(next);
		}
	}
	for (i = 0; i < N; i++) cout << total[i] << '\n';

	return 0;
}