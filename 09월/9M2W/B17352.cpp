#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 100000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;

int find(int X) {
	if (X == v[X]) return X;
	else return v[X] = find(v[X]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y, N;
	int A, B;
	cin >> N;
	v.resize(N, 0);
	A = B = -1;
	for (i = 0; i < N; i++) v[i] = i;
	for (i = 2; i < N; i++) {
		cin >> x >> y;
		x--, y--;
		x = find(x);
		y = find(y);
		if (x > y) swap(x, y);
		v[y] = x;
	}
	for (i = 0; i < N; i++) {
		if (v[i] == i) {
			if (A == -1) A = i;
			else B = i;
		}
	}
	cout << A + 1 << ' ' << B + 1;

	return 0;
}