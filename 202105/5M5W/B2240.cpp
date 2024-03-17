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

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, x, T, W, result;
	cin >> T >> W;
	v.resize(W + 1, -1);
	v[0] = 0;
	for (t = 0; t < T; t++) {
		cin >> x;
		for (i = W; i > 0; i--) {
			if (v[i - 1] != -1) v[i] = max(v[i], v[i - 1]) + ((x % 2) ^ (i % 2));
		}
		if (x == 1) v[0]++;
	}
	result = 0;
	for (i = 0; i <= W; i++) result = max(result, v[i]);
	cout << result;
	return 0;
}