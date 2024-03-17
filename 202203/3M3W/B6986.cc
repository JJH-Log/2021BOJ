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

int N, K;
double v[100000];
double total;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	for (int i = K; i < N - K; i++) total += v[i];
	cout << (total / (N - 2 * K) + 1e-9) << '\n';
	total += v[K] * K;
	total += v[N - 1 - K] * K;
	cout << (total / N + 1e-9) << '\n';
	
	return 0;
}