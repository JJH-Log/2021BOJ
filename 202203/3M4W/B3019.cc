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

vector<vector<int>> v = { {0}, {0, 0, 0, 0}, {0, 0}, {0, 0, 1}, {1, 0}
		,{1, 0, 0}, {0, 1}, {0, 0, 0}, {0, 1}, {1, 0}
		,{1, 0, 1}, {0, 0, 0}, {0, 0}, {0, 1, 1}, {2, 0}
		,{0, 0, 0}, {0, 0}, {1, 1, 0}, {0, 2} };
vector<int> b = { 0, 2, 3, 5, 7, 11, 15, 19 };

int C, P, h[100], res;

bool isInstallable(int now, int idx) {
	vector<int> tar = v[idx];
	if (now + tar.size() > C) return false;
	for (int i = 0; i < tar.size(); i++) {
		if (h[now + i] - tar[i] != h[now] - tar[0]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> C >> P; P--;
	for (int i = 0; i < C; i++) cin >> h[i];

	for (int i = 0; i < C; i++) {
		for (int j = b[P]; j < b[P + 1]; j++) {
			if (isInstallable(i, j)) res++;
		}
	}
	cout << res;

	return 0;
}