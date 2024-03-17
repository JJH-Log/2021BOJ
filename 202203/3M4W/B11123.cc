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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[100][100];
bool vtd[100][100];
int N, M, res;
string s;

void dfs(int x, int y) {
	vtd[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int dx = x + "2011"[i] - '1';
		int dy = y + "1120"[i] - '1';
		if ((dx >= 0) && (dx < N) && (dy >= 0) && (dy < M) && v[dx][dy] && !vtd[dx][dy]) dfs(dx, dy);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> s;
			for (int j = 0; j < M; j++) {
				if (s[j] == '#') v[i][j] = 1;
				else v[i][j] = 0;
				vtd[i][j] = false;
			}
		}
		res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[i][j] && !vtd[i][j]) {
					res++;
					dfs(i, j);
				}
			}
		}
		cout << res << '\n';
	}

	return 0;
}