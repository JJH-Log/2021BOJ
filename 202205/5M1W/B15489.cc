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

lld p[31][31], res;
int R, C, W;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	
	p[0][0] = p[1][0] = p[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) p[i][j] = 1;
			else p[i][j] = p[i - 1][j] + p[i - 1][j - 1];
		}
	}

	cin >> R >> C >> W;
	R--, C--;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j <= i; j++) res += p[R + i][C + j];
	}
	cout << res;
	
	return 0;
}
