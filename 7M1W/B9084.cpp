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
vector<vector<int>> w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t, N, M, T;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		v.resize(N, 0);
		for (i = 0; i < N; i++) cin >> v[i];
		cin >> M;
		w.resize(2, vector<int>(M + 1, 0));
		w[0][0] = 1;
		for (i = 0; i < N; i++) {
			for (j = 0; j <= M; j++) {
				if (v[i] > j) w[1][j] = w[0][j];
				else w[1][j] = w[1][j - v[i]] + w[0][j];
			}
			w[0] = w[1];
			w[1].clear();
			w[1].resize(M + 1, 0);
		}
		cout << w[0][M] << '\n';
		v.clear();
		w.clear();
	}
	return 0;
}