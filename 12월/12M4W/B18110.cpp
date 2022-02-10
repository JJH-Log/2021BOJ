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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, v[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	if (!N) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	int ct = round((double)N * 0.15);
	double total = 0;
	for (int i = ct; i < N - ct; i++) total += v[i];
	cout << round(total / ((double)N - 2 * ct));

	return 0;
}
