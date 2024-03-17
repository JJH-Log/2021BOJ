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


int L, N;
int rm, rM;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int x, T;
	cin >> T;
	while (T--) {
		cin >> L >> N;
		rm = 0; rM = 0;
		for (int i = 0; i < N; i++) {
			cin >> x;
			rm = max(rm, min(L - x, x));
			rM = max(rM, max(L - x, x));
		}
		cout << rm << ' ' << rM << '\n';
	}

	return 0;
}