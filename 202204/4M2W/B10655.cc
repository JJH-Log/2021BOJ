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


struct pos {
	int x, y;
};

int dist(pos a, pos b) { return abs(a.x - b.x) + abs(a.y - b.y); }
pos v[100000];
int N, total, res;



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i].x >> v[i].y;
		if (i) total += dist(v[i - 1], v[i]);
	}
	res = 2e9;
	for (int i = 2; i < N; i++) res = min(res, total - dist(v[i - 1], v[i]) - dist(v[i - 2], v[i - 1]) + dist(v[i - 2], v[i]));
	cout << res;

	return 0;
}