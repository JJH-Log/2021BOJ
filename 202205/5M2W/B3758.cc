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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct team {
	int name;
	int score;
	int submit_cnt;
	int submit_time;
};

bool cmp_team(team a, team b) {
	if (a.score == b.score) {
		if (a.submit_cnt == b.submit_cnt) return a.submit_time < b.submit_time;
		return a.submit_cnt < b.submit_cnt;
	}
	return a.score > b.score;
}

team v[101];
int problem[101][101];
int T, n, k, t, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> k >> t >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) problem[i][j] = 0;
			v[i] = { i, 0, 0, 1000 };
		}

		int id, pid, sc;
		for (int c = 1; c <= m; c++) {
			cin >> id >> pid >> sc;
			problem[id][pid] = max(problem[id][pid], sc);
			v[id].submit_cnt++;
			v[id].submit_time = c;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) v[i].score += problem[i][j];
		}
		sort(v + 1, v + n + 1, cmp_team);

		for (int i = 1; i <= n; i++) if (v[i].name == t) cout << i << '\n';
	}

	return 0;
}