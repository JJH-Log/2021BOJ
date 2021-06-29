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

	int i, N;
	cin >> N;
	v.resize(N, vector<int>(3, 0));
	N--;
	v[0][0] = 1;
	v[0][1] = 1;
	v[0][2] = 0;
	for (i = 1; i < N; i++) {
		v[i][0] = (v[i - 1][1] + v[i - 1][2]) % 1000000007;
		v[i][1] = (v[i - 1][0] + v[i - 1][2]) % 1000000007;
		v[i][2] = (v[i - 1][1] + v[i - 1][0]) % 1000000007;
	}
	if (N == 0) cout << 0;
	else cout << v[N - 1][0];
	return 0;
}
