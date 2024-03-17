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
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;




int getGrundy(int X) {
	int cnt = 0;
	while (!(X % 2)) cnt++, X /= 2;
	return cnt + 1;
}

// 규칙 발견을 위한 최초 접근법
int v[1000000];
int getGrundy2(int X) {
	int tmp[15] = { 0, };
	for (int i = 1; i <= X; i++) {
		if (X % i == 0) tmp[v[X - i]] = 1;
	}
	for (int i = 0; i < 15; i++) if (tmp[i] == 0) return i;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
	for (int i = 1; i <= 1000; i++) v[i] = getGrundy(i);
	for (int i = 1; i <= 1000; i++) {
		cout << v[i] << ' ';
		if (i % 10 == 0) cout << '\n';
	}*/
	int r, g;
	cin >> r >> g;
	r = getGrundy(r);
	g = getGrundy(g);
	char winner = (r ^ g) ? 'A' : 'B';
	cout << winner << " player wins";


	return 0;
}
