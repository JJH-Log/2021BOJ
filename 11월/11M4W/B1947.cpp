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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000000
#define BOUND 100000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld pre[11] = { 1, 328159686, 77259686, 826359686, 575459686, 324559686, 73659686, 822759686, 571859686, 320959686, 70059686 };
	int N, X;
	lld ans;

	cin >> N;
	X = N / BOUND;
	ans = pre[X];
	for (int i = X * BOUND; i <= N; i++) {
		ans = (ans * i) % MOD;
		if (i % 2) ans = (ans - 1 + MOD) % MOD;
		else ans = (ans + 1) % MOD;
	}
	cout << ans;


	return 0;
}
