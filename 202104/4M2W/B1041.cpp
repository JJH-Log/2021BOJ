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

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, N;
	int c1, c2, c3, m1;
	long long result = 0;
	v.resize(6, 0);

	cin >> N;
	for (i = 0; i < 6; i++) cin >> v[i];

	c1 = 51;
	c2 = 101;
	m1 = -1;
	for (i = 0; i < 6; i++) {
		c1 = min(c1, v[i]);
		m1 = max(m1, v[i]);
	}
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if ((i != j) && (i != 5 - j)) c2 = min(c2, v[i] + v[j]);
		}
	}
	c3 = min(v[0], v[5]) + min(v[1], v[4]) + min(v[2], v[3]);


	if (N == 1) result = v[0] + v[1] + v[2] + v[3] + v[4] + v[5] - m1;
	if (N == 2) result = 4 * c2 + 4 * c3;
	if (N >= 3) {
		N -= 2;
		result += ((long long)5 * N * N + 4 * N) * c1;
		result += ((long long)8 * N + 4) * c2;
		result += (long long)4 * c3;
	}
	cout << result << endl;
	return 0;
}

