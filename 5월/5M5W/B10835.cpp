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
vector<int> u;
vector<int> d;

int tmax(int x, int y, int z) {
	if (x >= y && x >= z) return x;
	else if (y >= x && y >= z) return y;
	return z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int N;
	int result;
	cin >> N;
	v.resize(2, vector<int>(N, 0));
	for (i = 0; i < N; i++) cin >> v[0][i];
	for (i = 0; i < N; i++) cin >> v[1][i];
	u.resize(N, 0);
	result = 0;
	for (i = 1; i < N; i++) {
		d.clear();
		d.resize(N, -2000);
		if (v[0][0] > v[1][i - 1] && u[0] != -2000) d[0] = u[0] + v[1][i - 1];
		for (j = 1; j < N; j++) {
			if (v[0][j] > v[1][i - 1] && u[j] != -2000) d[j] = tmax(d[j - 1], u[j - 1], u[j] + v[1][i - 1]);
			else d[j] = max(d[j - 1], u[j - 1]);
		}
		result = max(result, d[N - 1]);
		swap(u, d);
	}
	for (j = 0; j < N; j++) {
		if (v[0][j] > v[1][i - 1]) result = max(result, u[j] + v[1][i - 1]);
	}
	cout << result;
	return 0;
}