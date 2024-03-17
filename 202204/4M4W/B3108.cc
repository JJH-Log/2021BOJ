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

struct square {
	int x1, x2, y1, y2;
};

bool meet(square a, square b) {
	if (b.y2 > a.y2 && a.x2 < b.x2 && a.y1 > b.y1 && b.x1 < a.x1) return false;
	if (a.y2 > b.y2 && b.x2 < a.x2 && b.y1 > a.y1 && b.x1 > a.x1) return false;
	if (b.y1 > a.y2 || b.x1 > a.x2 || a.y1 > b.y2 || b.x2 < a.x1) return false;
	return true;
}


int N, u[1001];
square v[1001];

int find(int X) {
	if (u[X] == X) return X;
	return u[X] = find(u[X]);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		u[i] = i;
		cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
	}
	int res = N;
	for (int i = 0; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (meet(v[i], v[j])) {
				int a, b;
				a = find(i), b = find(j);
				if (a != b) {
					res--;
					if (a > b) swap(a, b);
					u[b] = a;
				}
			}
		}
	}
	cout << res;

	return 0;
}
