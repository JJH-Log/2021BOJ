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

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, N, M, x, y, d;
	cin >> N >> M;
	v.resize(N, vector<int>(N, 1e9));
	for (i = 0; i < M; i++) {
		cin >> x >> y >> d;
		v[x - 1][y - 1] = min(v[x - 1][y - 1], d);
	}
	for (i = 0; i < N; i++) v[i][i] = 0;
	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (v[i][j] == 1e9) cout << "0 ";
			else cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}