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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, M, R;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	R = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) q.push(i);
	for (int i = 0; i < M; i++) {
		int cnt, x;
		cin >> x, cnt = 0;
		while (q.front() != x) {
			cnt++;
			q.push(q.front());
			q.pop();
		}
		R += min(cnt, (int)q.size() - cnt);
		q.pop();
	}
	cout << R;

	return 0;
}
