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

int N, M;
priority_queue<lld, vector<lld>, greater<lld>> pq;
lld res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	while (M--) {
		lld now1 = pq.top();
		pq.pop();
		lld now2 = pq.top();
		pq.pop();
		pq.push(now1 + now2);
		pq.push(now1 + now2);
	}
	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}
	cout << res;


	return 0;
}