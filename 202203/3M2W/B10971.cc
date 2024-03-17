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
#define MOD 1000000007
#define BOUND 1000000000
#define MAXN 200005
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int N;
int FIN;
vector<vector<int>> w;
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, i, j, next;
	cin >> N;
	FIN = (1 << N) - 1;
	v.resize(FIN + 1, vector<int>(N, (int)1e9));
	w.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) cin >> w[i][j];
	}
	v[0][0] = 0;
	for (t = 0; t < FIN; t++) {
		for (i = 0; i < N; i++) {
			if (v[t][i] != (int)1e9) {
				for (j = 0; j < N; j++) {
					if (w[i][j] && ((t & (1 << j)) == 0)) {
						next = t | (1 << j);
						v[next][j] = min(v[next][j], v[t][i] + w[i][j]);
					}
				}
			}
		}
	}
	cout << v[FIN][0];
	return 0;
}
