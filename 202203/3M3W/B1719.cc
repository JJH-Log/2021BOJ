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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
int v[201][201];
int ans[201][201];

int trace(int s, int e) {
	if (ans[s][e] == e) return e;
	return trace(s, ans[s][e]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				ans[i][j] = j;
				ans[j][i] = i;
				v[i][j] = 1e9;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		v[x][y] = v[y][x] = d;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (v[i][j] > v[i][k] + v[k][j]) {
					ans[i][j] = k;
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << '-' << ' ';
			else cout << trace(i, j) << ' ';
		}
		cout << '\n';
	}

	return 0;
}