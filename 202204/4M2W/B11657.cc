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

vector<pii> w[500];
lld dist[500];
int N, M;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) dist[i] = 1e9;
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d; x--, y--;
		w[x].push_back({ y, d });
	}
	dist[0] = 0;
	for (int t = 0; t < N - 1; t++) {
		for (int i = 0; i < N; i++) {
			if (dist[i] == 1e9) continue;
			for (auto tar : w[i]) {
				if (dist[tar.first] > dist[i] + tar.second) dist[tar.first] = dist[i] + tar.second;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (dist[i] == 1e9) continue;
		for (auto tar : w[i]) {
			if (dist[tar.first] > dist[i] + tar.second) {
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		if (dist[i] == 1e9) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}

	return 0;
}