#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p, q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n >> p >> q;
		pq.push({ p, 1 });
		pq.push({ q, -1 });
	}
	int result, now;
	result = now = 0;
	while (!pq.empty()) {
		now += pq.top().second;
		result = max(result, now);
		pq.pop();
	}
	cout << result;

	
	return 0;
}