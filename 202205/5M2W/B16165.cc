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

map<string, int> team_idx;
map<string, string> name_info;
vector<string> team[100];
int N, M, T;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string team_name, team_member;
		cin >> team_name >> T;
		team_idx[team_name] = i;
		while (T--) {
			cin >> team_member;
			team[i].push_back(team_member);
			name_info[team_member] = team_name;
		}
	}
	for (int i = 0; i < M; i++) {
		string tar;
		cin >> tar >> T;
		if (T == 0) {
			int idx = team_idx[tar];
			sort(team[idx].begin(), team[idx].end());
			for (auto x : team[idx]) cout << x << '\n';
		}
		else cout << name_info[tar] << '\n';
	}

	return 0;
}