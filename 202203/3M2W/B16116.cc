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
#define MOD 1000000007
#define BOUND 1000000000
#define MAXN 500005
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

char cube[8][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	for (int i = 0; i < 8; i++) {
		getline(cin, s);
		cube[i][0] = s[0]; cube[i][1] = s[2]; cube[i][2] = s[4];
	}

	bool res = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				if (i != k) {
					for (int l = 0; l < 3; l++) {
						if (cube[k][l] == cube[i][j] && cube[k][(l + 2) % 3] == cube[i][(j + 1) % 3]) cnt++;
					}
				}
			}
			if (cnt != 1) res = false;
		}
	}
	cout << (res ? "YES" : "NO");
	return 0;
}
