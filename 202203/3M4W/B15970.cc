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
#include <string.h>
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

vector<int> w[5001];
int x, y, N;
lld res;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		w[y].push_back(x);
	}

	for (auto v : w) {
		if (!v.size()) continue;
		sort(v.begin(), v.end());
		res += v[1] - v[0];
		res += v[v.size() - 1] - v[v.size() - 2];
		for (int i = 1; i < v.size() - 1; i++) res += min(v[i] - v[i - 1], v[i + 1] - v[i]);
	}
	cout << res;
	

	return 0;
}