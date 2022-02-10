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


int N, M, result;
vector<string> v;
vector<vector<int>> w;

int ans(int x, int y) {
	int t;
	if (w[x][y] == 2) return 0;
	if (w[x][y] == 1) {
		result++;
		return 1;
	}
	w[x][y]++;
	if (v[x][y] == 'D') t = ans(x + 1, y);
	if (v[x][y] == 'U') t = ans(x - 1, y);
	if (v[x][y] == 'L') t = ans(x, y - 1);
	if (v[x][y] == 'R') t = ans(x, y + 1);
	if (!t) {
		w[x][y] = 2;
		return 0;
	}
	else {
		if (w[x][y] == 2) return 0;
		else {
			w[x][y]++;
			return 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	cin >> N >> M;
	v.resize(N);
	w.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++) cin >> v[i];
	result = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			ans(i, j);
		}
	}
	cout << result;
	return 0;
}
