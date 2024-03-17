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
#define BOUND 200000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int R, C, K, w[10][10];
int table[40][40];

struct sticker {
	int v[10][10];
	int N, M;
	void _input(int x, int y) {
		N = x, M = y;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) cin >> v[i][j];
		}
	}
	void _turn() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) w[j][N - 1 - i] = v[i][j];
		}
		swap(N, M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) v[i][j] = w[i][j];
		}
	}
	bool _insert(int x, int y) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (table[x + i][y + j] + v[i][j] == 2) return false;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) table[x + i][y + j] += v[i][j];
		}
		return true;
	}
};

sticker v[100];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		v[i]._input(x, y);
	}
	for (int i = 0; i < K; i++) {
		bool FLAG = true;
		for (int loop = 0; FLAG && loop < 4; loop++) {
			for (int x = 0; FLAG && x + v[i].N <= R; x++) {
				for (int y = 0; FLAG && y + v[i].M <= C; y++) {
					if (v[i]._insert(x, y)) FLAG = false;
				}
			}
			v[i]._turn();
		}
	}
	int res = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) if (table[i][j]) res++;
	}
	cout << res;


	return 0;
}