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
#define MOD 1234567
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, Q;
int v[100001];
int u[100001];
int cnt[100001][2];
int a, b;

int find(int X) {
	if (X == u[X]) return X;
	return u[X] = find(u[X]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> Q;
	iota(u + 1, u + N + 1, 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		cnt[i][v[i]]++;
	}
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		a = find(a);
		b = find(b);
		if (a == b) continue;
		if (a > b) swap(a, b);
		u[b] = a;
		cnt[a][0] += cnt[b][0];
		cnt[a][1] += cnt[b][1];
	}
	for (int i = 1; i <= Q; i++) {
		cin >> a;
		a = find(a);
		cout << (cnt[a][0] < cnt[a][1]) << '\n';
	}

	return 0;
}