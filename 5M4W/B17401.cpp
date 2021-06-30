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
#define MOD 1000000007

vector<vector<vector<int>>> v;

vector<vector<int>> conv(vector<vector<int>> A, vector<vector<int>> B) { //same size
	vector<vector<int>> result;
	int i, j, k, L;
	L = A.size();
	result.resize(L, vector<int>(L, 0));
	for (i = 0; i < L; i++) {
		for (j = 0; j < L; j++) {
			for (k = 0; k < L; k++) {
				result[i][j] = (((long long)A[i][k] * B[k][j]) + result[i][j]) % MOD;
			}
		}
	}
	return result;
}

vector<vector<int>> cal(vector<vector<int>> X, int N) {
	vector<vector<int>> result;
	int L = X.size();
	result.resize(L, vector<int>(L, 0));
	for (int i = 0; i < L; i++) result[i][i] = 1;
	while (N) {
		if (N % 2 == 1) result = conv(result, X);
		X = conv(X, X);
		N = (N >> 1);
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t, T, N, D, M;
	int a, b, c, tar;
	vector<vector<int>> result;
	cin >> T >> N >> D;
	v.resize(T, vector<vector<int>>(N, vector<int>(N, 0)));
	for (t = 0; t < T; t++) {
		cin >> M;
		for (i = 0; i < M; i++) {
			cin >> a >> b >> c;
			v[t][a - 1][b - 1] += c;
		}
	}

	tar = D / T;
	result.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) result[i][i] = 1;
	if (tar) {
		for (t = 0; t < T; t++) result = conv(result, v[t]);
	}
	result = cal(result, tar);

	for (t = 0; t < T; t++) {
		if (t < (D % T)) result = conv(result, v[t]);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
