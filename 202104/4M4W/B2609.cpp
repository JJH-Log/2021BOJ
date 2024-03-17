#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
using namespace std;


vector<int> v;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	while (y) {
		x = x % y;
		swap(x, y);
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, N, M;
	cin >> N >> M;
	A = gcd(N, M);
	cout << A << "\n" << N * M / A;
	
}

