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
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


priority_queue<pair<int, int>> pq;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		pq.push({ y, x });
	}
	int fin = 1000000;
	pair<int, int> now;
	while (!pq.empty()) {
		now = pq.top();
		pq.pop();
		fin = min(fin, now.first);
		fin -= now.second;
	}
	cout << max(fin, -1);
	
	return 0;
}