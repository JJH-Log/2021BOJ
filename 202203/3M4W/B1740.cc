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

string encode(lld X) {
	string ans = "";
	while (X) {
		ans += ((X % 2) ? '1' : '0');
		X /= 2;
	}
	return ans;
}

lld decode(string X) {
	lld ans = 0;
	lld j = 1;
	for (int i = 0; i < X.size(); i++, j *= 3) if (X[i] == '1') ans += j;
	return ans;
}

lld N;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	s = encode(N);
	cout << decode(s);

	return 0;
}