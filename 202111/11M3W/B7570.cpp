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

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, t;

	cin >> N;
	v.resize(N, -1);
	M = 0;
	for (int i = 0; i < N; i++) {
		cin >> t;
		t--;
		if (t) v[t] = v[t - 1] + 1;
		else v[0] = 0;
		M = max(M, v[t]);
	}
	cout << N - M - 1;

	return 0;
}
