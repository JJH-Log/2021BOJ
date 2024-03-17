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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

bool res[100011];

int base[10] = { 1, 2, 6, 10, 16, 22, 26, 30, 36, 40 };
int pp[5] = { 4 ,12, 4, 4, 10 };
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int now = 40;
	int idx = 0;
	for (auto num : base) res[num] = 1;
	while (now <= 100000) {
		now += pp[idx];
		idx = (idx + 1) % 5;
		res[now] = 1;
	}
	string ans;
	ans = (res[M] && res[N]) ? "hs" : "sh";
	cout << ans;

	return 0;
}
