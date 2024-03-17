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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld bnd, gap;
lld N, K, tar;
lld num, idx;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bnd = 9, gap = 1;
	cin >> N >> K;
	while (N >= 0) {
		if (K <= bnd * gap) {
			tar = ((K - 1) / gap) + 1;
			if (N < tar) cout << -1;
			else {
				num = tar + (bnd / 9) - 1;
				idx = (K + gap - 1) % gap;
				cout << to_string(num)[idx];
			}
			return 0;
		}
		else {
			K -= bnd * gap;
			N -= bnd;
			bnd *= 10;
			gap++;
		}
	}
	cout << -1;

	return 0;
}