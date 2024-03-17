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

string res;
int K;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	res = "";

	int len = 1;
	int t = 2;
	while (K > t) {
		K -= t;
		t <<= 1;
		len++;
	}
	K--;

	while (K) {
		res += '4' + 3 * (K % 2);
		K /= 2;
	}
	for (int i = res.size(); i < len; i++) res += '4';
	reverse(res.begin(), res.end());
	cout << res;
	
	return 0;
}