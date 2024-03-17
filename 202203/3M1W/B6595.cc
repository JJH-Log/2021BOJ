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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
vector<int> w[100000];
int cnt[100000];
bool kill[100000];
queue<pii> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	for (int i = 0; i < N; i++) {
		cnt[i] = w[i].size();
		if (cnt[i] == 1) q.push({ i, 1 });
	}
	int now_depth = 1;
	while (q.size() > 2) {
		while (q.front().second == now_depth) {
			pii now = q.front();
			kill[now.first] = true;
			q.pop();
			for (auto tar : w[now.first]) {
				cnt[tar]--;
				if (cnt[tar] == 1) q.push({ tar, now_depth + 1 });
			}
		}
		now_depth++;
	}
	for (int i = 0; i < N; i++) if (!kill[i]) cout << i << ' ';

	return 0;
}
