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

vector<vector<vector<int>>> v;
vector<vector<int>> f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N;
	cin >> N;
	v.resize(N + 2, vector<vector<int>>(N + 2, vector<int>(3, 0)));
	f.resize(N + 2, vector<int>(N + 2, 0));
	for (i = 1; i <= N; i++) { for (j = 1; j <= N; j++) cin >> f[i][j]; }
	v[1][2][0] = 1;
	for (i = 1; i <= N; i++) {
		for (j = 3; j <= N; j++) {
			if (!f[i][j]) {
				v[i][j][0] = v[i][j - 1][0] + v[i][j - 1][2];
				v[i][j][1] = v[i - 1][j][1] + v[i - 1][j][2];
				if (!f[i - 1][j] && !f[i][j - 1]) v[i][j][2] = v[i - 1][j - 1][0] + v[i - 1][j - 1][1] + v[i - 1][j - 1][2];
				//cout << i << " " << j << " " << v[i][j][0] << " " << v[i][j][1] << " " << v[i][j][2] << endl;
			}
		}
	}
	cout << v[N][N][0] + v[N][N][1] + v[N][N][2];
	return 0;
}