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

pll v[100000];
int N;
lld total, res, x, y;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		total += v[i].second;
	}
	total = (total + 1) / 2; //half point
	sort(v, v + N);

	for (int i = 0; i < N; i++) {
		res += v[i].second;
		if (res >= total) {
			cout << v[i].first;
			return 0;
		}
	}

	return 0;
}