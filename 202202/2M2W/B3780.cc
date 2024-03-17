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


int par[20000];
int dist[20000];

int find(int X) {
	if (X == par[X]) return X;
	int idx = find(par[X]);
	dist[X] += dist[par[X]];
	return par[X] = idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, T;
	char c;
	int x, y;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			par[i] = i;
			dist[i] = 0;
		}
		while (true) {
			cin >> c;
			if (c == 'O') break;
			if (c == 'E') {
				cin >> x, x--;
				find(x);
				cout << dist[x] << '\n';
			}
			if (c == 'I') {
				cin >> x >> y, x--, y--;
				dist[x] = abs(x - y) % 1000;
				par[x] = y;
			}
		}
	}

	return 0;
}
