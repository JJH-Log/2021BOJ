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

int N, res;
string q[100];
int an[2][100];
char w[3];
bool lock[10];

bool check() {
	int ans[2];
	for (int i = 0; i < N; i++) {
		ans[0] = ans[1] = 0;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (q[i][j] == w[k]) ans[j == k]++;
			}
		}
		if (ans[0] != an[0][i] || ans[1] != an[1][i]) return false;
	}
	return true;
}

void backTracking(int cnt) {
	if (cnt == 3) {
		res += check();
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!lock[i]) {
			lock[i] = true;
			w[cnt] = '0' + i;
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> q[i] >> an[1][i] >> an[0][i];
	backTracking(0);
	cout << res;

	return 0;
}
