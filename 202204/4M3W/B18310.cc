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

int N, x, v[100001];
int idx, cnt;
lld total;
lld res;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v[x]++;
		total += x;
	}
	res = 1e12; idx = 0;
	for (int i = 1; i <= 100000; i++) {
		total += cnt * 2 - N;
		if (total < res) {
			res = total;
			idx = i;
		}
		cnt += v[i];
	}
	cout << idx;

	return 0;
}