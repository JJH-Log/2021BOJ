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

int T, N;
int w[20];
int lock[20];
string s;

void backTracking(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) cout << s[w[i]];
		cout << '\n';
		return;
	}

	char before = ' ';
	for (int i = 0; i < N; i++) {
		if (!lock[i] && before != s[i]) {
			lock[i] = true;
			w[cnt] = i;
			before = s[i];
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> s;
		sort(s.begin(), s.end());
		N = s.size();

		backTracking(0);

	}

	return 0;
}