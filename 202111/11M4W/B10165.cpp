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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct info {
	int n, s, e;
};

vector<info> v;
priority_queue<int, vector<int>, greater<int>> pq;
int N, M;

bool compare(info A, info B) {
	if (A.s == B.s) return A.e > B.e;
	return A.s < B.s;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxE = 0;
	cin >> N >> M;
	v.resize(M);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) maxE = max(maxE, y), y += N;
		v[i] = { i + 1, x, y };
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < M; i++) {
		if (v[i].e > maxE) {
			maxE = v[i].e;
			pq.push(v[i].n);
		}
	}
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}


	return 0;
}
