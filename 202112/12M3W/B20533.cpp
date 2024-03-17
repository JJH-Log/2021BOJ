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

lld v[500010];
lld pre[500010];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> v[i];
	sort(v + 1, v + N + 1, greater<lld>());
	pre[0] = 0;
	for (int i = 1; i <= N; i++) pre[i] = pre[i - 1] + (lld)v[i];

	lld ans = -1;
	int cnt = 0;
	for (int i = 1; cnt < 100 && i + 6 <= N; i++) {
		for (int j = i + 1; (j < i + 20) && j <= N; j++) {
			for (int k = j + 1; (k < j + 20) && (k + 4) <= N; k++) {
				if ((v[i] < v[j] + v[k]) && (v[j] + v[k] < pre[k + 4] - pre[k])) ans = max(ans, v[i] + v[j] + v[k] + pre[k + 4] - pre[k]);
			}
		}
		if (ans != -1) cnt++;
	}

	cout << ans;

	return 0;
}
