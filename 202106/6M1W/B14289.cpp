#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
#define MOD 1000000007
using namespace std;

vector<vector<int>> v;
vector<vector<int>> R;
int N;
vector<vector<int>> conv(vector<vector<int>> A, vector<vector<int>> B) { //size = 8;
	int i, j, k;
	vector<vector<int>> result;

	result.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				result[i][j] = ((long long)result[i][j] + ((long long)A[i][k] * B[k][j])) % MOD;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, M, D, x, y;
	cin >> N >> M;
	v.resize(N, vector<int>(N, 0));
	for (i = 0; i < M; i++) cin >> x >> y, v[x - 1][y - 1] = 1, v[y - 1][x - 1] = 1;
	cin >> D;
	while (D) {
		if (D % 2) {
			if (!R.size()) R = v;
			else R = conv(R, v);
		}
		v = conv(v, v);
		D /= 2;
	}
	cout << R[0][0];
	return 0;
}