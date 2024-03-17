#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<string> solve(int t) {
	string tmp;
	map<string, int> m;
	vector<int> v(t);
	vector<string> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> tmp;
		m[tmp] = i;
	}
	for (int i = 0; i < t; i++) {
		cin >> tmp;
		v[i] = m[tmp];
	}
	for (int i = 0; i < t; i++) {
		cin >> tmp;
		ans[v[i]] = tmp;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, T;
	vector<string> res;
	cin >> T;
	while (T--) {
		cin >> N;
		res = solve(N);
		for (auto x : res) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}