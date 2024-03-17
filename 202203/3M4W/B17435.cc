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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N, Q;
int v[20][200000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[0][i], v[0][i]--;
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < N; j++) {
			v[i][j] = v[i - 1][v[i - 1][j]];
		}
	}
	
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int n, x, idx, t;
		cin >> n >> x; x--;
		idx = 0, t = 1;
		while (n) {
			if (n % 2) x = v[idx][x];
			n /= 2;
			idx++;
			t <<= 1;
		}
		cout << x + 1 << '\n';
	}
	
	return 0;
}