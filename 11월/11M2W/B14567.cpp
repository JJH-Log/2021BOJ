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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> v;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(N, 1);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ --x, --y });
	}
	while (!pq.empty()) {
		pii now = pq.top();
		v[now.second] = max(v[now.second], v[now.first] + 1);
		pq.pop();
	}
	for (int i = 0; i < N; i++) cout << v[i] << ' ';


	return 0;
}
