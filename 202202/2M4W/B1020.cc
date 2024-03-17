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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;

string s;
int num[10] = { 6,2,5,5,4,5,6,3,7,5 };
int dp[16][110][2];

int solve(int p, int left, bool over) {
	if (left < 0) return 10;
	if (p == s.size()) return (over && !left ? 0 : 10);
	int& ret = dp[p][left][over];
	if (ret != -1) return ret;

	ret = 10;
	for (int i = (over ? 0 : s[p] - '0'); i < 10; i++) {
		int next = solve(p + 1, left - num[i], over || (i > s[p] - '0'));
		if (next != 10) {
			ret = i;
			break;
		}
	}
	return ret;
}

lld ans, result;
void go(int p, int left, bool over) {
	if (p == s.size()) return;
	int& ret = dp[p][left][over];
	ans = ans * 10 + ret;
	go(p + 1, left - num[ret], over || (ret > s[p] - '0'));
}

lld tenPos(int X) {
	return (X ? 10 * tenPos(X - 1) : 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string now;
	cin >> now;

	int sum = 0;
	for (auto c : now) sum += num[c - '0'];

	memset(dp, -1, sizeof(dp));
	s = string(now.size(), '0');
	solve(0, sum, 0);
	go(0, sum, 0);

	result = ans - stoll(now) + tenPos(s.size());

	memset(dp, -1, sizeof(dp));
	s = now;
	if (solve(0, sum, 0) != 10) {
		ans = 0;
		go(0, sum, 0);
		result = ans - stoll(now);
	}
	cout << result;
	
	return 0;
}
