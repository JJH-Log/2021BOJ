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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, k;
	int N, M;
	int s, e, b;
	cin >> N >> M;
	v.resize(N, vector<int>(N, 500));
	for (i = 0; i < N; i++) v[i][i] = 0;
	for (i = 0; i < M; i++) {
		cin >> s >> e >> b;
		if (b) v[s - 1][e - 1] = 0, v[e - 1][s - 1] = 0;
		else v[s - 1][e - 1] = 0, v[e - 1][s - 1] = 1;
	}
	
	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
		}
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> s >> e;
		cout << v[s - 1][e - 1] << '\n';
	}


	return 0;
}