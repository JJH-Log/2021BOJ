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

int N, M, A, B, x, y;
vector<int> w[1001];
int dist[1001];
queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dist[A] = 1;
	q.push(A);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto tar : w[now]) {
			if (!dist[tar]) {
				dist[tar] = dist[now] + 1;
				q.push(tar);
			}
		}
	}
	cout << dist[B] - 1;

	return 0;
}