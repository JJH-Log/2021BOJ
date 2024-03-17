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

int N;
lld v[100000];
lld w[100000];
lld best, ans, dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) cin >> w[i];
	best = w[0];
	ans = 0;
	for (int i = 1; i < N; i++) {
		dist += v[i];
		if (best > w[i]) {
			ans += best * dist;
			best = w[i];
			dist = 0;
		}
	}
	if (dist) ans += best * dist;
	cout << ans;
	
	return 0;
}
