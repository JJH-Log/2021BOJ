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

priority_queue<pii, vector<pii>, greater<pii>> pq;
int p[100];
int K, N;

int mlt(int X, int Y) {
	return min((lld)X * Y, (lld)MAXINT);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> p[i];
		pq.push({ p[i], i });
	}
	pii now;
	while (!pq.empty() && N--) {
		now = pq.top();
		for (int i = now.second; i < K; i++) pq.push({ mlt(now.first, p[i]), i });
		pq.pop();
	}
	cout << now.first;
	

	return 0;
}
