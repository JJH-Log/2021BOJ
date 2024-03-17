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

int N, M, res;
vector<int> w[501];
int d[501];
queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	d[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (d[now] == 3) continue;
		for (auto next : w[now]) {
			if (!d[next]) {
				d[next] = d[now] + 1;
				q.push(next);
				res++;
			}
		}
	}
	cout << res;

	return 0;
}