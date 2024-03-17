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
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
int P, L;
int m[100];
int cut[100], w[100];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		for (int j = 0; j < P; j++) cin >> m[j];
		if (P < L) cut[i] = 1;
		else{
			sort(m, m + P, greater<int>());
			cut[i] = m[L - 1];
		}
	}
	sort(cut, cut + N);
	w[0] = cut[0];
	for (int i = 1; i < N; i++) w[i] = w[i - 1] + cut[i];

	int idx = upper_bound(w, w + N, M) - w;
	cout << idx;

	return 0;
}