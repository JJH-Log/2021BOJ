#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, order[10], w[10];
char ch;
bool lock[10];
lld res1, res2;
bool FLAG;

void backTracking(int cnt) {
	if (cnt == N + 1) {
		for (int i = 0; i < N; i++) {
			if (order[i] == 0 && w[i] > w[i + 1]) return;
			if (order[i] == 1 && w[i] < w[i + 1]) return;
		}
		lld ans = 0;
		for (int i = 0; i < N + 1; i++) {
			ans *= 10;
			ans += w[i];
		}

		if (!FLAG) {
			res1 = res2 = ans;
			FLAG = true;
		}
		else {
			res1 = max(res1, ans);
			res2 = min(res2, ans);
		}
	}

	for (int i = 0; i < 10; i++) {
		if (!lock[i]) {
			lock[i] = true;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}

void print(lld x, int sz) {
	string tar = to_string(x);
	for (int i = 0; i < sz - tar.size(); i++) cout << 0;
	cout << tar;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch;
		if (ch == '>') order[i] = 1;
	}
	backTracking(0);
	print(res1, N + 1);
	cout << '\n';
	print(res2, N + 1);

	return 0;
}