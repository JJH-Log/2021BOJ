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
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v;
int divs[] = { 1, 10, 100, 1000 };
int N, M;

int nextNum(int X, int div) {
	if (((X / div) % 10) == 9) return X - 9 * div;
	else return X + div;
}

int rec(int turn, int now) {
	if (turn == M) return turn % 2 ? now <= N : now > N;
	if (v[turn][now] != -1) return v[turn][now];
	v[turn][now] = 0;
	for (auto i : divs) v[turn][now] |= !rec(turn + 1, nextNum(now, i));
	return v[turn][now];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(M + 1, vector<int>(10000, -1));
	if (rec(0, N)) cout << "koosaga";
	else cout << "cubelover";

	return 0;
}