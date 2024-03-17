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
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int nA, nB, M;
int res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	bool FLAG;
	cin >> nA >> nB >> M;
	if ((nA % 2) && (nB % 2)) FLAG = true;
	else FLAG = false;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (FLAG && (x % 2) && (y % 2)) FLAG = false;
	}
	res = (nA + nB) / 2;
	if (FLAG) res--;

	cout << res;

	return 0;
}