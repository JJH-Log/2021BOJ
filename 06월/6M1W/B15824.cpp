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

vector<int> v;
vector<int> w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, result;
	cin >> N;
	v.resize(N, 0);
	w.resize(N + 1, 1);
	for (i = 0; i <= N; i++) {
		if (i!=N) cin >> v[i];
		if (i) w[i] = (w[i - 1] * 2) % MOD;
	}
	if (N == 1) {
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	result = 0;
	for (i = 1; i < N; i++) {
		result = (((lld)v[i] - v[i - 1]) * (((long long)w[N] - w[i] - w[N - i] + 1 + MOD + MOD) % MOD) + result) % MOD;
	}
	cout << result;
	return 0;
}