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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, K, total;
int v[10000];
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);


	for (int i = 1; i < N; i++) pq.push(v[i] - v[i - 1]);
	total = v[N - 1] - v[0]; K--;
	while (K-- && !pq.empty()) {
		total -= pq.top();
		pq.pop();
	}
	cout << total;

	return 0;
}