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
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, X, Hs, Ha, Hb, Hc, Ws, Wa, Wb, Wc;
lld H[5000000];
lld W[5000000];
lld res, next, p, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		cin >> N >> X >> Hs >> Ha >> Hb >> Hc >> Ws >> Wa >> Wb >> Wc;
		H[0] = Hs % Hc + 1;
		W[0] = Ws % Wc + 1;
		for (int i = 1; i < N; i++) {
			H[i] = H[i - 1] + 1
				+ (H[i - 1] * Ha + Hb) % Hc;
			W[i] = (W[i - 1] * Wa + Wb) % Wc + 1;
		}
		int i, j, nidx;
		i = j = res = 0;
		while (i < N && j < N) {
			if (i == j) i++;
			else if (abs(H[i] - H[j]) > X) (H[i] > H[j] ? j++ : i++);
			else {
				res = max(res, H[i] * W[i] + H[j] * W[j]);
				(H[i] * W[i] > H[j] * W[j]) ? j++ : i++;
			}
		}
		if (res) cout << res << '\n';
		else cout << "-1\n";
	}

	return 0;
}
