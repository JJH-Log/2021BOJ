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
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[1000];
int N, M, shift;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	lld result = 0;
	cin >> N >> M;
	fill(v, v + M, 0);
	int before = 0;
	v[0] = 1;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v[(before + t) % M]++;
		before = (before + t) % M;
	}
	for (int i = 0; i < M; i++) result += (lld)v[i] * ((lld)v[i] - 1) / 2;
	cout << result;

	return 0;
}
