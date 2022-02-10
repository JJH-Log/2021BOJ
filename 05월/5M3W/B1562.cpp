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
#define MOD 1000000000

int N;

long long ans(vector<long long> v0) {
	vector<vector<long long>> v;
	int i, j, len;
	long long result;
	len = v0.size();
	v.resize(N, vector<long long>(len, 0));
	v[0] = v0;
	for (i = 1; i < N; i++) {
		v[i][0] = v[i - 1][1];
		v[i][len - 1] = v[i - 1][len -2];
		for (j = 1; j < (len - 1); j++) {
			v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % MOD;
		}
	}
	result = 0;
	for (i = 0; i < len; i++) result += v[N - 1][i];
	return result % MOD;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	long long a0, a1, a2, a3;
	long long temp, result;
	cin >> N;
	temp = 0; result = 0;
	a0 = ans(vector<long long>{0, 1, 1, 1, 1, 1, 1, 1, 1, 1});
	a1 = ans(vector<long long>{0, 1, 1, 1, 1, 1, 1, 1, 1});
	a2 = ans(vector<long long>{1, 1, 1, 1, 1, 1, 1, 1, 1});
	a3 = ans(vector<long long>{1, 1, 1, 1, 1, 1, 1, 1});
	result = a0 + a3 - a1 - a2;
	while (result < 0) result += MOD;
	cout << result;
	return 0;
}
