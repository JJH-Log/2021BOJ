#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

#define MOD 1000000007
vector<long long> X;
vector<long long> R;

vector<long long> conv(vector<long long> x, vector<long long> y) {
	vector<long long> temp;
	temp.push_back(((x[0] * y[0]) % MOD + (x[1] * y[2]) % MOD) % MOD);
	temp.push_back(((x[0] * y[1]) % MOD + (x[1] * y[3]) % MOD) % MOD);
	temp.push_back(((x[0] * y[2]) % MOD + (x[2] * y[3]) % MOD) % MOD);
	temp.push_back(((x[1] * y[2]) % MOD + (x[3] * y[3]) % MOD) % MOD);
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	X.resize(4, 1);
	R.resize(4, 1);
	X[3] = 0;
	R[1] = 0;
	R[2] = 0;
	N--;
	while (N) {
		if (N % 2) R = conv(X, R);
		X = conv(X, X);
		N = N >> 1;
	}
	cout << R[0];
	return 0;
}