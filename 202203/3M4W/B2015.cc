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

lld N, K, res, v[200001], w[200001];
map<lld, int> m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> v[i];
	
	m[0] = 1;
	for (int i = 1; i <= N; i++) {
		w[i] = v[i] + w[i - 1];
		if (m.count(w[i] - K)) res += m[w[i] - K];
		if (m.count(w[i])) m[w[i]]++;
		else m[w[i]] = 1;
	}
	cout << res;

	return 0;
}