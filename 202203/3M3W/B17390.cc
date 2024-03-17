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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, Q;
int v[300001];
lld w[300001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> v[i];
	sort(v + 1, v + N + 1);
	for (int i = 1; i <= N; i++) w[i] = w[i - 1] + v[i];

	for (int i = 0; i < Q; i++){
		int x, y;
		cin >> x >> y;
		cout << w[y] - w[x - 1] << '\n';
	}


	return 0;
}