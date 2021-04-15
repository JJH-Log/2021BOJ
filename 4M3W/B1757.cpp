#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, temp;
	cin >> N >> M;

	v.resize(N, vector<int>(M + 1, 0));

	cin >> temp;
	v[0][1] = temp;
	for (i = 1; i < N; i++) {
		cin >> temp;
		for (j = 1; (j <= M) && (j <= (i + 1)); j++) {
			v[i][j] = v[i - 1][j - 1] + temp;
		}
		v[i][0] = v[i - 1][0];
		if (i == 1) v[i][0] = max(v[i][0], v[i - 1][1]);
		for (j = 1; (j <= M) && (j <= (i - 1)); j++) {
			v[i][0] = max(v[i][0], v[i - j][j]);
		}
	}
	cout << v[N - 1][0];

	return 0;
}
