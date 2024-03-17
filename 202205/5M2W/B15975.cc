#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, x, y;
vector<int> v[100001];
lld res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v[y].push_back(x);
	}
	for (int i = 1; i <= 100000; i++) {
		if (v[i].size() <= 1) continue;
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) res += v[i][1] - v[i][0];
			else if (j == v[i].size() - 1) res += v[i][v[i].size() - 1] - v[i][v[i].size() - 2];
			else res += min(v[i][j] - v[i][j - 1], v[i][j + 1] - v[i][j]);
		}
	}
	cout << res;

	return 0;
}