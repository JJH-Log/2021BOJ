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

set<vector<bool>> S;

int N, M;
vector<bool> v[100000];
int o, x, y;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 20; j++) v[i].push_back(0);
	}
	for (int i = 0; i < M; i++) {
		cin >> o >> x; x--;
		if (o < 3) {
			cin >> y; y--;
			v[x][y] = 2 - o;
		}
		if (o == 3) {
			for (int i = 20; i > 0; i--) v[x][i] = v[x][i - 1];
			v[x][0] = 0;
		}
		if (o == 4) {
			for (int i = 0; i < 19; i++) v[x][i] = v[x][i + 1];
			v[x][19] = 0;
		}
	}
	for (int i = 0; i < N; i++) S.insert(v[i]);
	cout << S.size();

	return 0;
}