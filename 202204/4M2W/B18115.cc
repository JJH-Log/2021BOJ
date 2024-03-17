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

int N, i, j, k, x;
int res[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	i = 1, j = 2, k = N;
	for (int t = N; t >= 1; t--) {
		cin >> x;
		if (x == 1) {
			res[i] = t;
			i = j;
			j = i + 1;
		}
		if (x == 2) {
			res[j] = t;
			j++;
		}
		if (x == 3) {
			res[k] = t;
			k--;
		}
	}
	for (int t = 1; t <= N; t++) cout << res[t] << ' ';
	
	
	return 0;
}