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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, K;
vector<int> cut[2];
int x, y;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		cut[x].push_back(y);
	}
	sort(cut[0].begin(), cut[0].end());
	sort(cut[1].begin(), cut[1].end());

	x = y = 0;
	int idx = 0;
	for (auto tar : cut[0]) {
		x = max(x, tar - idx);
		idx = tar;
	}
	x = max(x, N - idx);

	idx = 0;
	for (auto tar : cut[1]) {
		y = max(y, tar - idx);
		idx = tar;
	}
	y = max(y, M - idx);

	cout << x * y;
	
	return 0;
}
