#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, result;
	int t1, t2, t3, t4;
	cin >> N >> M;
	v.resize(N + 1, vector<int>(N + 1, 0));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> v[i][j];
			v[i][j] += (v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1]);
		}
	}
	for (i = 0; i < M; i++) {
		cin >> t1 >> t2 >> t3 >> t4;
		cout << v[t3][t4] - v[t3][t2 - 1] - v[t1 - 1][t4] + v[t1 - 1][t2 - 1] << "\n";
	}
}