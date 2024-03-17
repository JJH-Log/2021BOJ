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

int v[100020], tar;
int coin[4] = { 1,2,5,7 };
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fill(v, v + 100020, 1e9);
	v[0] = 0;
	v[1] = v[2] = v[5] = v[7] = 1;
	for (int i = 1; i < 100000; i++) {
		for (int j = 0; j < 4; j++) v[i + coin[j]] = min(v[i + coin[j]], v[i] + 1);
	}
	cin >> tar;
	cout << v[tar];

	return 0;
}