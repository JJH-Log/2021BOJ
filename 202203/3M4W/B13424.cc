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

int N, M, K;
int v[100][100];
int f[100];
int total, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) v[i][j] = 0;
				else v[i][j] = 1e9;
			}
		}

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c; a--, b--;
			v[a][b] = v[b][a] = c;
		}

		for (int k = 0; k < N; k ++ ) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
				}
			}
		}

		cin >> K;
		for (int i = 0; i < K; i++) cin >> f[i], f[i]--;

		total = 1e9, res = 0;
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (int j = 0; j < K; j++) tmp += v[f[j]][i];
			if (tmp < total) {
				total = tmp;
				res = i;
			}
		}
		cout << res + 1 << '\n';
	}

	return 0;
}