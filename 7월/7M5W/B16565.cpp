#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 10007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<lld> ft;

lld modPow(lld X, lld N) {
	lld R = 1;
	while (N) {
		if (N % 2) R = (R * X) % MOD;
		X = (X * X) % MOD;
		N /= 2;
	}
	return R;
}

lld modC(int R, int C) {
	return (ft[R] * modPow(ft[R - C], MOD - 2) * modPow(ft[C], MOD - 2)) % MOD;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ft.resize(53, 0);
	ft[0] = 1;
	for (int i = 1; i < 53; i++) {
		ft[i] = ft[i - 1] * i % MOD;
	}
	int N;
	lld result = 0;
	cin >> N;
	for (int i = 1; N - 4 * i >= 0; i++) {
		if (i % 2) result = (result + modC(13, i) * modC(52 - 4 * i, N - 4 * i)) % MOD;
		else result = (MOD + result - (modC(13, i) * modC(52 - 4 * i, N - 4 * i)) % MOD) % MOD;
	}
	cout << result;


	return 0;
}