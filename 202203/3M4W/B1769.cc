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

string X;

int strsum(string x) {
	int ans = 0;
	for (auto c : x) ans += c - '0';
	return ans;
}

int next(int N) {
	int ans = 0;
	while (N) {
		ans += N % 10;
		N /= 10;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> X;
	if (X.size() == 1) {
		cout << 0 << '\n';
		if ((X[0] - '0') % 3 == 0) cout << "YES";
		else cout << "NO";
	}
	else {
		int now = strsum(X);
		int cnt = 1;
		while (now > 9) {
			now = next(now);
			cnt++;
		}
		cout << cnt << '\n';
		if (now % 3 == 0) cout << "YES";
		else cout << "NO";
	}


	return 0;
}