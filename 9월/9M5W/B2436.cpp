#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>

#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int gcd(int X, int Y) {
	if (!Y) return X;
	if (X < Y) return gcd(Y, X);
	return gcd(Y, X % Y);
}
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int K = M / N;
	int A;
	A = (int)sqrt(K);

	while (A) {
		if (!(K % A) && (gcd(K / A, A) == 1)) {
			cout << A * N << ' ' << K / A * N;
			return 0;
		}
		A--;
	}
	
	return 0;
}