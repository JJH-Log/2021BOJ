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

int gca(int A, int B) {
	if (A < B) return gca(B, A);
	int temp;
	while (B) {
		temp = A % B;
		A = B;
		B = temp;
	}
	return A;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A * B / gca(A, B) << '\n';
	}
	return 0;
}