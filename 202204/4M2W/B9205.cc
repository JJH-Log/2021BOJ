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

int getDist(pos a, pos b) { return abs(a.x - b.x) + abs(a.y - b.y); }
int T, N;
int u[102];
pos v[102];

int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N + 2; i++) {
			cin >> v[i].x >> v[i].y;
			u[i] = i;
		}
		for (int i = 0; i < N + 2; i++) {
			for (int j = i; j < N + 2; j++) {
				if (getDist(v[i], v[j]) <= 1000) {
					int a = find(i);
					int b = find(j);
					if (a > b) swap(a, b);
					u[b] = a;
				}
			}
		}
		if (find(0) == find(N + 1)) cout << "happy\n";
		else cout << "sad\n";
	}

	return 0;
}