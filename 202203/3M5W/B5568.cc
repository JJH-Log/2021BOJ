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

int N, K, w[4], lock[10];
string v[10];
set<string> S;

void backTracking(int cnt) {
	if (cnt == K) {
		string ans = "";
		for (int i = 0; i < K; i++) ans += v[w[i]];
		S.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!lock[i]) {
			lock[i] = true;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	backTracking(0);
	cout << S.size();

	return 0;
}