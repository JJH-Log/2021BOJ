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
vector<vector<int>> R;

vector<vector<int>> vsq(vector<vector<int>> A, vector<vector<int>> B) {
	int i, j, k, l, N;
	vector<vector<int>> temp;
	N = A.size();
	temp.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) temp[i][j] += A[i][k] * B[k][j];
			temp[i][j] %= 1000;
		}
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	long long B;
	cin >> N >> B;
	v.resize(N, vector<int>(N, 0));
	R.resize(N, vector<int>(N, 0));
	for (i = 0; i < N * N; i++) cin >> v[i / N][i % N];
	for (i = 0; i < N; i++) R[i][i] = 1;
	while (B) {
		if (B % 2) R = vsq(R, v);
		v = vsq(v, v);
		B /= 2;
	}
	for (i = 0; i < N * N; i++) {
		cout << R[i / N][i % N] << " ";
		if (i % N == N - 1) cout << "\n";
	}
	return 0;
}