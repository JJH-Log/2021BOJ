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

int N, M;
string v[501];
int res[5];


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < 5 * N + 1; i++) cin >> v[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x = 1 + 5 * i;
			int y = 1 + 5 * j;
			int cnt = 0;
			while (v[x][y] == '*') x++, cnt++;
			res[cnt]++;
		}
	}
	for (auto x : res) cout << x << ' ';

	return 0;
}
