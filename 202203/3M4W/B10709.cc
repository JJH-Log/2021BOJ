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

int H, W;
int v[100][100];
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		int tar = -1;
		for (int j = 0; j < W; j++) {
			if (s[j] == 'c') v[i][j] = tar = 0;
			else v[i][j] = tar == -1 ? -1 : ++tar;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}