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

int N, K, v[50];
string res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	int bcnt = 0;

	for (int i = N - 1; i - bcnt > 0; i--) {
		if (K >= i - bcnt) {
			K -= i - bcnt;
			bcnt++;
			v[i] = 1;
		}
	}
	res = "";
	for (int i = 0; i < N; i++) res += (v[i] ? 'B' : 'A');
	if (K) cout << -1;
	else cout << res;


	return 0;
}