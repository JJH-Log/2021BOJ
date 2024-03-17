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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<lld> v;
lld N, L;
bool res;

bool solve(lld m) {
	lld tar = N - v[m];
	if (tar < 0) return true;
	if (tar % m == 0) {
		for (int i = 0; i < m; i++) cout << (tar / m) + i << ' ';
		res = true;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	v.push_back(0); //dummy
	v.push_back(0); //dummy
	v.push_back(1); //for 2
	for (lld i = 3; i <= 100; i++) v.push_back( v[i - 1] + i - 1 );
	cin >> N >> L;
	for (lld i = L; i <= 100; i++) if (solve(i)) break;
	if (!res) cout << -1;

	return 0;
}