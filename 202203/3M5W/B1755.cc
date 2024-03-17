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
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int M, N;
string tar[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<pair<string, int>> v;

string encode(int X) {
	if (X < 10) return tar[X];
	else return tar[X / 10] + " " + tar[X % 10];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = M; i <= N; i++) v.push_back({ encode(i), i });
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
		if (i % 10 == 9) cout << '\n';
	}

	return 0;
}