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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int v[100][100];
int r[100][100];
int N, M;
vector<int> ans;

void solve(int S, int E) {
	if (S == E || v[S][E] == 1e9) return;
	if (r[S][E] == -1) {
		ans.push_back(S);
		ans.push_back(E);
		return;
	}
	solve(S, r[S][E]);
	ans.pop_back();
	solve(r[S][E], E);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(i != j) v[i][j] = 1e9;
			r[i][j] = -1;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		v[x - 1][y - 1] = min(v[x - 1][y - 1], d);
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
					r[i][j] = k;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) cout << 0 << ' ';
			else cout << (v[i][j] == 1e9? 0 : v[i][j]) << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) cout << 0 << '\n';
			else {
				ans.clear();
				solve(i, j);
				cout << ans.size() << ' ';
				for (auto tar : ans) cout << tar + 1 << ' ';
				cout << '\n';
			}
		}
	}

	return 0;
}
