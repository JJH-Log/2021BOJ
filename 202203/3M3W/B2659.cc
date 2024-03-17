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
#define BOUND 1000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 500005
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

set<int> s;
vector<int> cn;
int w[4];

int clocknum(int t[]) {
	int ans = 1e4;
	for (int i = 0; i < 4; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			tmp *= 10;
			tmp += t[(i + j) % 4];
		}
		ans = min(ans, tmp);
	}
	return ans;
}

void backTracking(int cnt) {
	if (cnt == 4) {
		int num = clocknum(w);
		if (!s.count(num)) {
			s.insert(num);
			cn.push_back(num);
		}
		return;
	}
	for (int i = 1; i <= 9; i++) {
		w[cnt] = i;
		backTracking(cnt + 1);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v[4];
	backTracking(0);
	for (int i = 0; i < 4; i++) cin >> v[i];
	sort(cn.begin(), cn.end());
	cout << lower_bound(cn.begin(), cn.end(), clocknum(v)) - cn.begin() + 1;
	
	return 0;
}