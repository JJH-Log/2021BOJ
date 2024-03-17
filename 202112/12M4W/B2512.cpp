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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, v[10000];
lld M;

int diff(int x) {
	if (!x) return v[x];
	else return v[x] - v[x - 1];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	cin >> M;
	sort(v, v + N);

	int i = 0;
	lld money = 0;
	while (i < N && (money + diff(i) * ((lld)N - i) <= M)) {
		money += diff(i) * ((lld)N - i);
		i++;
	}
	if (i == N) cout << v[N - 1];
	else cout << v[i - 1] + (M - money) / ((lld)N - i);
	return 0;
}
