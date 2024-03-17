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

int N, L, now, t, D, R, G;
int r[1001];
int g[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> D >> R >> G;
		r[D] = R, g[D] = G;
	}

	while (now != L) {
		if (!r[now]) now++;
		else if ((t % (r[now] + g[now])) >= r[now]) now++;
		t++;
	}
	cout << t;

	return 0;
}
