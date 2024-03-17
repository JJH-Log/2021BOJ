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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int x, n;
};

bool compare(info a, info b) {
	return a.x < b.x;
}

int N, K, S, res;
info v[30000], vm[30000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K >> S;
	int j, k, x, n;
	j = k = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> n;
		x -= S;
		if (x < 0) vm[k++] = { -x, n };
		if (x > 0) v[j++] = { x, n };
	}
	sort(v, v + j, compare);
	sort(vm, vm + k, compare);

	bool FLAG;
	int fill;
	
	FLAG = true, fill = 0;
	for (int i = j - 1; i >= 0; i--) {
		fill += v[i].n;
		if (fill >= K) {
			if (!FLAG) fill -= K;
			res += (fill / K) * v[i].x * 2;
			fill %= K;
			FLAG = true;
		}
		if (fill && FLAG) {
			FLAG = false;
			res += v[i].x * 2;
		}
	}
	
	FLAG = true, fill = 0;
	for (int i = k - 1; i >= 0; i--) {
		fill += vm[i].n;
		if (fill >= K) {
			if (!FLAG) fill -= K;
			res += (fill / K) * vm[i].x * 2;
			fill %= K;
			FLAG = true;
		}
		if (fill && FLAG) {
			FLAG = false;
			res += vm[i].x * 2;
		}
	}
	cout << res;

	return 0;
}