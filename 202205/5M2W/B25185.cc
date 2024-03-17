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
#define MOD 1234567
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int X;
string c[4];
string tar = "mps";
int v[3][9];

bool isRest() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) v[i][j] = 0;
	}
	sort(c, c + 4);
	for (int i = 0; i < 4; i++) v[tar.find(c[i][1])][c[i][0] - '1']++;
	if (c[0] == c[1] && c[1] == c[2]) return true;
	if (c[1] == c[2] && c[2] == c[3]) return true;
	if (c[0] == c[1] && c[2] == c[3]) return true;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			if (v[i][j] && v[i][j + 1] && v[i][j + 2]) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> X;
	for (int x = 0; x < X; x++) {
		for (int i = 0; i < 4; i++) cin >> c[i];
		if (isRest()) cout << ":)\n";
		else cout << ":(\n";
	}
	
	return 0;
}