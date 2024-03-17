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

int T, N;
int res[(1 << 15)];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 1; i * i < (1 << 15); i++) {
		int t0 = i * i;
		res[t0]++;
		for (int j = i; t0 + j * j < (1 << 15); j++) {
			int t1 = t0 + j * j;
			res[t1]++;
			for (int k = j; t1 + k * k < (1 << 15); k++) {
				int t2 = t1 + k * k;
				res[t2]++;
				for (int l = k; t2 + l * l < (1 << 15); l++) {
					int t3 = t2 + l * l;
					res[t3]++;
				}
			}
		}
	}
	
	while (true) {
		cin >> N;
		if (!N) break;
		cout << res[N] << '\n';
	}

	return 0;
}
