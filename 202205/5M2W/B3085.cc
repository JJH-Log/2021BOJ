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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, res;
char v[50][50];
string w[50];

int cnt() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 1;
			for (int t = j; t < N && v[i][j] == v[i][t]; t++) tmp = max(tmp, t - j + 1);
			for (int t = i; t < N && v[i][j] == v[t][j]; t++) tmp = max(tmp, t - i + 1);
			ans = max(tmp, ans);
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> w[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) v[i][j] = w[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != N - 1) {
				swap(v[i][j], v[i][j + 1]);
				res = max(res, cnt());
				swap(v[i][j], v[i][j + 1]);
			}
			if (i != N - 1) {
				swap(v[i][j], v[i + 1][j]);
				res = max(res, cnt());
				swap(v[i][j], v[i + 1][j]);
			}
		}
	}
	cout << res;

	return 0;
}