#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<lld> v;

lld ans(lld X, lld P) {
	lld result = 1;
	while (P) {
		if (P % 2 == 1) result = (result * X) % MOD;
		X = (X * X) % MOD;
		P /= 2;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, P, N, K;
	v.resize(4000001, 0);
	v[0] = 1;
	for (i = 1; i <= 4000000; i++) v[i] = (v[i - 1] * i) % MOD;


	cin >> N >> K;
	cout << (v[N] * ans((v[N - K] * v[K]) % MOD, MOD - 2)) % MOD << '\n';

	return 0;
}