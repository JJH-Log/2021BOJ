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
#include <numeric>
#define MOD 1000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int u[500];
bool chk[500]; //is Graph?
int N, M, res;


int find(int X) {
	if (u[X] == X) return X;
	else return u[X] = find(u[X]);
}

void merge(int X, int Y) {
	X = find(X), Y = find(Y);
	if (X == Y) chk[X] = true;
	else {
		if (X > Y) swap(X, Y);
		u[Y] = X;
		chk[X] = chk[X] || chk[Y];
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	int T = 1;
	while (true) {
		cin >> N >> M;
		if (N == 0) return 0;
		iota(u, u + N, 0);
		fill(chk, chk + N, 0);

		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			merge(x - 1, y - 1);
		}
		res = 0;
		for (int i = 0; i < N; i++) {
			if (u[i] == i && !chk[i]) res++;
		}
		cout << "Case " << T++ << ": ";
		if (res > 1) cout << "A forest of "<< res <<" trees.\n";
		else if (res == 1) cout << "There is one tree.\n";
		else cout << "No trees.\n";
	}

	return 0;
}