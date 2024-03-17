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



int val1, val2;

int ans(int N) {
	return ((N / 6) * val1) + ((N % 6) * val2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int x, y;
	cin >> N >> M;
	
	val1 = val2 = 1e9;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		if (val1 > x) val1 = x;
		if (val1 > y * 6) val1 = y * 6;
		if (val2 > y) val2 = y;
	}
	int result = 0;
	if (N % 6) result = min(ans(N), ans(N + 6 - (N % 6)));
	else result = ans(N);

	cout << result;


	return 0;
}