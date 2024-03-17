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
#include <numeric>
#define MOD 1000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;



int J, N;
int v[1000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> J >> N;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			v[i] = x * y;
		}
		sort(v, v + N, greater<int>());
		int res = 0;
		while (v[res] < J) J -= v[res++];
		cout << res + 1 << '\n';
	}
	
	return 0;
}