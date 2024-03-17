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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld A, B, M, X, t, idx;
lld v[25];
vector<lld> res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> M;
	for (int i = M - 1; i >= 0; i--) cin >> v[i];
	t = 1;
	for (int i = 0; i < M; i++, t *= A) X += v[i] * t;

	idx = 0;
	while (X) {
		res.push_back(X % B);
		X /= B;
	}

	for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';



	return 0;
}
