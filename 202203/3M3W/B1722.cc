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

lld ft[21];
int v[21];
bool lock[21];
int N, op;
lld tar;

int getNum(int K) {
	for (int i = 1; i <= N; i++) {
		if (lock[i]) continue;
		K--;
		if (!K) {
			lock[i] = true;
			return i;
		}
	}
}

int getIdx(int K) {
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		if (lock[i]) continue;
		if (i == K) {
			lock[i] = true;
			return cnt;
		}
		cnt++;
	}
}

void sol1(int now) {
	if (now == 1) {
		cout << getNum(1);
		return;
	}
	int cnt = 1;
	while (tar > ft[now - 1]) {
		cnt++;
		tar -= ft[now - 1];
	}
	cout << getNum(cnt) << ' ';
	sol1(now - 1);
}

void sol2() {
	lld res = 0;
	for (int i = 1; i <= N; i++) {
		int t = getIdx(v[i]);
		for (int j = 1; j < t; j++) res += ft[N - i];
	}
	cout << res + 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ft[1] = 1;
	for (lld i = 2; i <= 20; i++) ft[i] = ft[i - 1] * i;
	cin >> N >> op;
	if (op == 1) {
		cin >> tar;
		sol1(N);
	}
	else {
		for (int i = 1; i <= N; i++) cin >> v[i];
		sol2();
	}

	return 0;
}