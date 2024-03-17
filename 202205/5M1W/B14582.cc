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


int v[2][9];
int score[2];
vector<int> diff;
bool now_winning;
bool reversal;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 2; i++) for (int j = 0; j < 9; j++) cin >> v[i][j];
	for (int t = 0; t < 9; t++) {
		score[0] += v[0][t];
		diff.push_back(score[0] - score[1]);
		score[1] += v[1][t];
		diff.push_back(score[0] - score[1]);
	}
	for (auto x : diff) {
		if (reversal) continue;
		if (now_winning && x < 0) reversal = true;
		if (x > 0) now_winning = true;
	}
	if (reversal && (score[0] < score[1])) cout << "Yes";
	else cout << "No";
	

	return 0;
}
