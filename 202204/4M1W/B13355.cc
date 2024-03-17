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
#define MOD 998244353
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, W, L, T, v[1000], b[100];

int _move() {
	int ans = 0;
	T++;
	for (int i = W - 1; i > 0; i--) {
		b[i] = b[i - 1];
		ans += b[i];
	}
	b[0] = 0;
	return ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> W >> L;
	for (int i = 0; i < N; i++) cin >> v[i];
	T = 0;
	for (int i = 0; i < N; i++) {
		while (_move() + v[i] > L);
		b[0] = v[i];
	}
	cout << T + W;

	return 0;
}