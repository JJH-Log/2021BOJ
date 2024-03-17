#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

#define MOD 1000000007
vector<int> mv;
int sz;

int ans(int X) {
	vector<int> v;
	int i;
	long long result;
	v.resize(sz, 0);
	v[0] = X;
	for (i = 1; i < sz; i++) v[i] = ((long long)v[i - 1] * v[i - 1]) % MOD;
	result = 1;
	for (i = 0; i < sz; i++) {
		if (mv[i]) result = (result * v[i]) % MOD;
	}
	return result;
}

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	while (y) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, i, a, b, c;
	long long result;

	int K = MOD - 2;
	while (K) mv.push_back(K % 2), K /= 2;
	sz = mv.size();

	cin >> M;
	result = 0;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		c = gcd(a, b);
		result = (result + ((long long)(b / c) * ans(a / c))) % MOD;
	}
	cout << result;
	return 0;
}