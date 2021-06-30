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
vector<bool> c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, L, p, q, total, result;
	cin >> N;
	c.resize(N + 1, false);

	for (i = 2; i <= N; i++) {
		if (c[i] == false) {
			v.push_back(i);
			for (j = 2 * i; j <= N; j += i) c[j] = true;
		}
	}

	p = 0; q = 0;
	L = v.size();
	total = 0; result = 0;
	while (true) {
		if (total < N) {
			if (q == v.size()) break;
			total += v[q];  q++;
		}
		else {
			if (total == N) result++;
			total -= v[p];  p++;
		}
	}
	cout << result;
	return 0;
}
