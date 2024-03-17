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

int v[260][130];
bool segment[10][7] = { {1, 1, 1, 0, 1, 1, 1},  {0, 0, 1, 0, 0, 1, 0}
	, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 1, 0, 1, 0}
	, {1, 1, 0, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0}
	, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1} };



int s, W, H;
string n;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s >> n;
	H = 2 * s + 3;
	W = (s + 3) * n.size();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			pii j_handle = { j % (s + 3), j / (s + 3) };
			if (i == 0 || i == s + 1 || i == 2 * s + 2) {
				if (j_handle.first == 0 || j_handle.first == s + 2 || j_handle.first == s + 1) continue;
				if(i == 0) v[i][j] = segment[n[j_handle.second] - '0'][0];
				if(i == s + 1) v[i][j] = segment[n[j_handle.second] - '0'][3];
				if(i == 2 * s + 2) v[i][j] = segment[n[j_handle.second] - '0'][6];
			}
			else {
				if (j_handle.first == 0 || j_handle.first == s + 1) {
					if (i == 0 || i == s + 1 || i == 2 * s + 2) continue;
					if (j_handle.first == 0 && i < s + 1) v[i][j] = 2 * segment[n[j_handle.second] - '0'][1];
					if (j_handle.first == 0 && i > s + 1) v[i][j] = 2 * segment[n[j_handle.second] - '0'][4];
					if (j_handle.first == s + 1 && i < s + 1) v[i][j] = 2 * segment[n[j_handle.second] - '0'][2];
					if (j_handle.first == s + 1 && i > s + 1) v[i][j] = 2 * segment[n[j_handle.second] - '0'][5];
				}
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W - 1; j++) {
			if (v[i][j] == 0) cout << ' ';
			if (v[i][j] == 1) cout << '-';
			if (v[i][j] == 2) cout << '|';
		}
		cout << '\n';
	}



	return 0;
}