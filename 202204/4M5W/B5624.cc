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

int N, v[5000];
bool vtd[400001];
lld res;

bool check(int idx) {
	for (int i = 0; i < idx; i++) if (vtd[200000 + v[idx] - v[i]]) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i] += 100000;
	}
	for (int i = 0; i < N; i++) {
		res += check(i);
		for (int j = 0; j < i; j++) vtd[v[j] + v[i]] = true;
		vtd[v[i] + v[i]] = true;
	}
	cout << res;
	
	return 0;
}
