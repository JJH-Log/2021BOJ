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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int val, cnt, la;
};

bool compare(info a, info b) {
	if (a.cnt == b.cnt) return a.la < b.la;
	return a.cnt > b.cnt;
}

int N, C;
vector<info> v;

void query(int tar, int idx) {
	for (auto& now : v) {
		if (now.val == tar) {
			now.cnt++;
			return;
		}
	}
	v.push_back({ tar, 1, idx });
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> C;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		query(x, i);
	}
	sort(v.begin(), v.end(), compare);

	for (auto now : v) {
		for (int i = 0; i < now.cnt; i++) cout << now.val << ' ';
	}


	return 0;
}