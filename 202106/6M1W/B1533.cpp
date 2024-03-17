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
#define MOD 1000003
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<int>> R;
vector<int> t;

vector<vector<int>> conv(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> result;
	result.resize(A.size(), vector<int>(B[0].size(), 0));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) {
				result[i][j] = (((lld)A[i][k] * B[k][j]) + result[i][j]) % MOD;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, N, S, E, T, t;
	vector<vector<int>> start;
	string s;
	cin >> N >> S >> E >> T;
	v.resize(5 * N, vector<int>(5 * N, 0));
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < N; j++) {
			t = s[j] - '0';
			if (t) v[5 * i][5 * j + t - 1] = 1;
		}
	}
	for (i = 0; i < 5 * N; i++) if (i % 5) v[i][i - 1] = 1;
	while (T) {
		if (T % 2) {
			if (!R.size()) R = v;
			else R = conv(R, v);
		}
		T /= 2;
		v = conv(v, v);
	}
	cout << R[5 * (S - 1)][5 * (E - 1)];
	return 0;
}