#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct query {
	int x, y, r;
};

int N, M;
string v[100];
int vtd[100][100];
vector<query> res;

bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == '*' && !vtd[i][j]) return false;
		}
	}
	return true;
}

int findMax(int x, int y) {
	for (int t = 1; ; t++) {
		for (int i = 0; i < 4; i++) {
			int dx = x + ("2011"[i] - '1') * t;
			int dy = y + ("1120"[i] - '1') * t;
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && v[dx][dy] == '*') continue;
			else return t - 1;
		}
	}
}

void fill(int x, int y, int r) {
	for (int t = 0; t <= r; t++) {
		for (int i = 0; i < 4; i++) {
			int dx = x + ("2011"[i] - '1') * t;
			int dy = y + ("1120"[i] - '1') * t;
			vtd[dx][dy] = true;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == '*') {
				int ans = findMax(i, j);
				if (ans) {
					fill(i, j, ans);
					res.push_back({ i, j, ans });
				}
			}
		}
	}
	if (!check()) cout << -1;
	else {
		cout << res.size() << '\n';
		for (auto p : res) cout << p.x + 1 << ' ' << p.y + 1 << ' ' << p.r << '\n';
	}

	return 0;
}