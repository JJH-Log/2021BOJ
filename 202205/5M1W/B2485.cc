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

int N, G;
int v[100000];
vector<int> diff;
lld res;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	for (int i = 1; i < N; i++) diff.push_back(v[i] - v[i - 1]);
	G = gcd(diff[0], diff[1]);
	for (int i = 1; i < diff.size(); i++) G = gcd(G, diff[i]);
	
	for (int i = 0; i < diff.size(); i++) res += (diff[i] / G) - 1;
	cout << res;


	return 0;
}
