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
#define BOUND 1000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 2002
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
int v[10000];

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];

	int idx, M;
	M = 0;
	for (idx = N - 1; idx >= 0 && v[idx] > M; idx--) {
		M = max(M, v[idx]);
		pq.push(v[idx]);
	}
	if (idx == -1) {
		cout << -1;
		return 0;
	}

	pq.push(v[idx]);
	for (int i = 0; i < idx; i++) cout << v[i] << ' ';

	bool FLAG = false;
	while (!pq.empty()) {
		if (!FLAG && v[idx] < pq.top()) {
			FLAG = true;
			cout << pq.top() << ' ';
		}
		else pq2.push(pq.top());
		pq.pop();
	}
	while (!pq2.empty()) {
		cout << pq2.top() << ' ';
		pq2.pop();
	}

	return 0;
}