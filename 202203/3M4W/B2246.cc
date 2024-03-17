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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int d, c;
};

info v[10000];
int N, res;

bool check1(int idx) {
	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		if (v[idx].d > v[i].d) {
			if (v[idx].c >= v[i].c) return false;
		}
	}
	return true;
}

bool check2(int idx) {
	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		if (v[idx].c > v[i].c) {
			if (v[idx].d >= v[i].d) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i].d >> v[i].c;
	for (int i = 0; i < N; i++) if (check1(i) && check2(i)) res++;
	cout << res;

	return 0;
}