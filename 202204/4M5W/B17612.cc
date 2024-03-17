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
#define MOD 86400
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int id, num, t;
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.t == b.t) return a.num < b.num;
		return a.t > b.t;
	}
};

int N, K, T, x, y;
priority_queue<int, vector<int>, greater<int>> npq;
priority_queue<info, vector<info>, cmp> pq;
vector<lld> res;
lld total;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= K; i++) npq.push(i);
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (npq.empty()) {
			T = pq.top().t;
			while (!pq.empty() && pq.top().t == T) {
				info now = pq.top();
				res.push_back(now.id);
				npq.push(now.num);
				pq.pop();
			}
		}
		pq.push({ x, npq.top(), T + y });
		npq.pop();
	}
	while (!pq.empty()) {
		res.push_back(pq.top().id);
		pq.pop();
	}
	for (int i = 0; i < N; i++) total += res[i] * (i + 1);
	cout << total;

	return 0;
}
