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
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int v[500001];
int N, X;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	lld result = 0;
	cin >> N >> X;
	int cnt = (X - 1000 * N) / 4000;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		result += b;
		pq.push(a - b);
	}
	while (!pq.empty() && cnt) {
		int diff = pq.top();
		pq.pop();
		if (diff > 0) {
			result += diff;
			cnt--;
		}
	}
	cout << result;

	return 0;
}
