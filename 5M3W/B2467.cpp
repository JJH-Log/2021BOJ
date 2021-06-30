#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;


vector<int> v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, result, temp, x, y;
	cin >> N;
	v.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	i = 0; j = N - 1;
	result = 2e9 + 1;
	while (j - i != 1) {
		temp = v[j] + v[i];
		if (!temp) {
			x = i, y = j;
			break;
		}
		if (abs(temp) < result) {
			x = i, y = j;
			result = abs(temp);
		}
		if (temp < 0) i++;
		if (temp > 0) j--;
	}
	temp = v[i] + v[j];
	if (abs(temp) < result) x = i, y = j;

	cout << v[x] << " " << v[y];

	return 0;
}