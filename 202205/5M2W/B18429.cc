#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, K, v[8], res;
int w[8];
bool lock[8];


void backTracking(int cnt) {
	if (cnt == N) {
		int weight = 500;
		for (int i = 0; i < N; i++) {
			weight += v[w[i]] - K;
			if (weight < 500) return;
		}
		res++;
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
	cout << res;

	return 0;
}