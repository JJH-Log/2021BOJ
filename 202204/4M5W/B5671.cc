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
#define MOD 86400
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, res;

bool isDup(int X) {
	bool v[10] = { 0, };
	while (X) {
		if (v[X % 10]) return true;
		v[X % 10] = true;
		X /= 10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> N;
		if (cin.eof()) break;
		cin >> M;
		for (int i = N; i <= M; i++) if (!isDup(i)) res++;
		cout << res << '\n';
		res = 0;
	}

	return 0;
}
