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

	int i, j, N;
	int result = 0;

	cin >> N;
	v.resize(N, vector<int>(10, 1));
	if (N == 1) result = 9;
	else {
		for (i = 1; i < N; i++) {
			v[i][0] = v[i - 1][1];
			v[i][9] = v[i - 1][8];
			for (j = 1; j < 9; j++) {
				v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % 1000000000;
			}
		}
		for (i = 1; i < 10; i++) result = (result + v[N - 1][i]) % 1000000000;
	}
	cout << result;
	return 0;
}
