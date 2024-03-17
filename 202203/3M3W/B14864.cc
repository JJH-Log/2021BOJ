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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int cnt, idx;
};

bool compare(info a, info b) {
	return a.cnt < b.cnt;
}

info v[100000]; //앞에있으면 --, 뒤에있으면 ++
int res[100000];
int N, M;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		v[i].cnt = N - 1 - i;
		v[i].idx = i;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y; x--, y--;
		v[x].cnt--, v[y].cnt++;
	}
	sort(v, v + N, compare);

	for (int i = 0; i < N; i++){
		if(v[i].cnt != i) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < N; i++) res[v[i].idx] = N - i;
	for (int i = 0; i < N; i++) cout << res[i] << ' ';

	return 0;
}