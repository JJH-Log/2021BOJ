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
#define MOD 1000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

double p[4][19];
double p1, p2;
double ans1, ans2;
lld c[19][19];

int pr[7] = { 2,3,5,7,11,13,17 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(10);
	cout << fixed;

	c[0][0] = 1;
	for (int i = 1; i <= 18; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) c[i][j] = 1;
			else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	cin >> p1 >> p2;
	p[0][1] = p1 / 100; p[1][1] = (100 - p1) / 100;
	p[2][1] = p2 / 100; p[3][1] = (100 - p2) / 100;

	for (int i = 2; i <= 18; i++) {
		for (int j = 0; j < 4; j++) p[j][i] = p[j][i - 1] * p[j][1];
	}
	
	for (auto now : pr) {
		ans1 += c[18][now] * p[0][now] * p[1][18 - now];
		ans2 += c[18][now] * p[2][now] * p[3][18 - now];
	}
	cout << 1 - (1 - ans1) * (1 - ans2);

	return 0;
}