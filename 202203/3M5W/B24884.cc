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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, W, T, K;
int res;

void simulation(vector<int> x, int t, int now, bool wood) {

	vector<int> w;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		if (i != 0 && x[i - 1]) cnt++;
		if (i != N - 1 && x[i + 1]) cnt++;
		if (wood && now == i) w.push_back(x[i]);
		else w.push_back(max(0, x[i] - (3 - cnt)));
	}
	if (t == T) {
		int cnt = 0;
		for (auto tar : w) if (tar) cnt++;
		if (cnt >= K) res++;
		return;
	}
	if (now != 0) simulation(w, t + 1, now - 1, true);
	simulation(w, t + 1, now, true);
	if (now != N - 1) simulation(w, t + 1, now + 1, true);


}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> W >> T >> K;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	simulation(v, 1, W, false);
	cout << res;
	return 0;
}