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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string pattern[4] = { "423131", "423141", "424231", "423231" };

pii idx[4] = { {3, 4}, {4, 5}, {1, 2}, {2, 3} };
pii ldx[4] = { {0, 1}, {1, 2}, {4, 5}, {0, 5} };
int K;

int v[6][2];

void swift() {
	int tmp[2] = { v[0][0], v[0][1] };
	for (int i = 1; i < 6; i++) {
		v[i - 1][0] = v[i][0];
		v[i - 1][1] = v[i][1];
	}
	v[5][0] = tmp[0];
	v[5][1] = tmp[1];
}


bool isMatch(int tar) {
	for (int i = 0; i < 6; i++) if (v[i][0] != pattern[tar][i] - '0') return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	for (int i = 0; i < 6; i++) cin >> v[i][0] >> v[i][1];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (isMatch(j)) {
				cout << (v[ldx[j].first][1] * v[ldx[j].second][1] - v[idx[j].first][1] * v[idx[j].second][1]) * K;
				return 0;
			}
		}
		swift();
	}



	return 0;
}
