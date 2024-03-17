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

map<int, int> mx;
map<int, int> my;
map<pii, int> ms;
int N, x, y;
lld res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (!mx.count(x)) mx[x] = 1;
		else mx[x]++;
		if (!my.count(y)) my[y] = 1;
		else my[y]++;
		if (!ms.count({ x, y })) ms[{x, y}] = 1;
		else ms[{x, y}]++;
	}
	for (auto tar : mx) if (tar.second > 1) res++;
	for (auto tar : my) if (tar.second > 1) res++;
	cout << res;

	return 0;
}
