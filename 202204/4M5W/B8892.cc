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
#define MOD 86400
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int T, K;
string v[100];


bool isP(string a, string b) {
	string tar, rtar;
	tar = a + b;
	rtar = tar;
	reverse(rtar.begin(), rtar.end());
	if (tar == rtar) {
		cout << tar << '\n';
		return true;
	}
	return false;
}

bool solve() {
	cin >> K;
	for (int i = 0; i < K; i++) cin >> v[i];
	for (int i = 0; i < K; i++) {
		for (int j = i + 1; j < K; j++) {
			if (isP(v[i], v[j]) || isP(v[j], v[i])) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) if (!solve()) cout << 0 << '\n';

	return 0;
}
