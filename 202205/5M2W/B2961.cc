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

struct info {
	lld sour, bitter;
};

info v[10];
lld S, B, res;
int N;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i].sour >> v[i].bitter;

	res = -1;
	for (int i = 1; i < (1 << N); i++) {
		S = B = -1;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				if (S == -1) S = v[j].sour, B = v[j].bitter;
				else {
					S *= v[j].sour;
					B += v[j].bitter;
				}
				if (S > 100000000000) break;
			}
		}
		if (res == -1) res = abs(S - B);
		else res = min(res, abs(S - B));
	}
	cout << res;


	return 0;
}