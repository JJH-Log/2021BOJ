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

int N, M, x;
int cnt[200000], b[200000], t[200000];
bool vtd[200000];
vector<int> w[200000];
queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		t[i] = -1;
		while (true) {
			cin >> x;
			if (!x) break;
			x--;
			w[i].push_back(x);
			w[x].push_back(i);
			cnt[i]++, cnt[x]++;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x; x--;
		t[x] = 0, q.push(x);
		vtd[x] = true;
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto tar : w[now]) {
			b[tar]++;
			if (!vtd[tar] && b[tar] * 2 >= cnt[tar]) {
				t[tar] = t[now] + 1;
				q.push(tar);
				vtd[tar] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) cout << t[i] << ' ';

	
	return 0;
}