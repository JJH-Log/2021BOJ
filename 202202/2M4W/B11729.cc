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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
using namespace std;
using lld = long long;
using pii = pair<int, int>;


int N;
void solve(int t, int s, int e) {
	if (t == 1) {
		cout << s << ' ' << e << '\n';
		return;
	}
	int tar = 6 - s - e;
	solve(t - 1, s, tar);
	solve(1, s, e);
	solve(t - 1, tar, e);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout << ((int)pow(2, N) - 1) << '\n';
	solve(N, 1, 3);

	return 0;
}
