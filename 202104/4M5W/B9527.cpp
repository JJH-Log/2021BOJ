#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

unsigned long long ans(unsigned long long X) {
	if (X == 0) return 0;
	unsigned long long result, t1, t2, N;
	N = 1;
	result = 0;
	while (true) {
		t1 = X / (N * 2);
		t2 = X % (N * 2);
		result += t1 * N;
		if (t2 >= N) result += (t2 - N + 1);
		if (t1 == 0) break;
		N *= 2;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long A, B;
	cin >> A >> B;
	cout << ans(B) - ans(A - 1);
}

