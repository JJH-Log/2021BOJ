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

string A, B;
bool res;

void solve(int idx, vector<int> bucket, bool flag, int now) {
	if (res) return;
	if (idx == B.size()) {
		cout << now;
		res = true;
	}
	int tar = flag ? 9 : B[idx] - '0';
	for (int i = tar; i >= 0; i--) {
		if (idx == 0 && i == 0) continue;
		if (!bucket[i]) continue;
		bucket[i]--;
		if (i == tar) solve(idx + 1, bucket, flag || false, now * 10 + i);
		else solve(idx + 1, bucket, true, now * 10 + i);
		bucket[i]++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	if (A.size() == B.size()) {
		vector<int> x;
		x.resize(10, 0);
		for (auto c : A) x[c - '0']++;
		solve(0, x, false, 0);
	}
	else if (A.size() < B.size()) {
		res = true;
		vector<char> x;
		for (auto c : A) x.push_back(c);
		sort(x.begin(), x.end(), greater<char>());
		for (auto c : x) cout << c;
	}
	if (!res) cout << -1;

	return 0;
}