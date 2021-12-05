#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int N, M;
vector<string> v;
set<string> s;
string parse(int x, int y, int d, string now) {
	now += v[x][y];
	int dx = x + "10"[d] - '0';
	int dy = y + "01"[d] - '0';
	if (dx == N || dy == M || v[dx][dy] == '#') return now;
	return parse(dx, dy, d, now);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string result;
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] != '#' && (!i || v[i - 1][j] == '#')) s.insert(parse(i, j, 0, ""));
			if (v[i][j] != '#' && (!j || v[i][j - 1] == '#')) s.insert(parse(i, j, 1, ""));
		}
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		if ((*it).size() > 1) {
			result = (*it);
			break;
		}
	}
	cout << result;

	return 0;
}