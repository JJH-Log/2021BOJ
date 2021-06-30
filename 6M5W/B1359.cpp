#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

int Com(int n, int r) {
	if (n < r) {
		return 0;
	}
	int t = min(r, n - r);
	int result = 1;
	for (int i = 1; i <= t; i++) {
		result *= n;
		result /= i;
		n--;
	}
	return result;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(11);
	int i, N, M, K;
	cin >> N >> M >> K;
	double result;
	result = 0;
	for (i = 1; K - i >= 0; i++) result += Com(M, K - i) * Com(N - M, M - K + i);
	result = 1 - result / Com(N, M);
	cout << result;
	return 0;
}