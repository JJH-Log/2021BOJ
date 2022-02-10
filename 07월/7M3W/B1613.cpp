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
#define INT_MIN -2147483647
#define INT_MAX 2147483647
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
int N, K, S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	v.resize(N, vector<int>(N, 10000));

	int i, j, k, x, y;
	for (i = 0; i < K; i++) {
		cin >> x >> y;
		v[x - 1][y - 1] = 1;
	}

	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) v[i][j] = min(v[i][k] + v[k][j], v[i][j]);
		}
	}

	cin >> S;
	for (i = 0; i < S; i++) {
		cin >> x >> y;
		if (v[x - 1][y - 1] != 10000) cout << -1;
		else if (v[y - 1][x - 1] != 10000) cout << 1;
		else cout << 0;
		cout << '\n';
	}

	return 0;
}