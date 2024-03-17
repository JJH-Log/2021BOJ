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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld v[31][31];

lld solve(int x, int y) {
	lld& res = v[x][y];
	if (res != -1) return res;
	res = 0;
	res += solve(x - 1, y + 1);
	if(y) res += solve(x, y - 1);
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) v[i][j] = i ? -1 : 1;
	}
	for (int i = 1; i <= 30; i++) solve(i, 0);

	int N;
	while (true) {
		cin >> N;
		if (!N) break;
		cout << v[N][0] << '\n';
	}
	
	return 0;
}