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

	int i, j, N, S, total, result;
	cin >> N >> S;
	v.resize(N + 1, 0);
	result = 1e9;
	for (i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] >= S) result = 1;
	}
	if (result == 1) {
		cout << result;
		return 0;
	}
	i = j = 0;
	total = v[0];
	while (true) {
		if (result == 2 || j == N) break;
		if (total < S) {
			j++;
			total += v[j];
		}
		else {
			result = min(result, j - i + 1);
			total -= v[i];
			i++;
		}
	}
	if (result == 1e9) cout << 0;
	else cout << result;

	return 0;
}