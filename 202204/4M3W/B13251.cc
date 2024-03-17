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

double N, M, K;
double p, v[50];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(12);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> v[i];
		N += v[i];
	}
	cin >> K;

	for (int i = 0; i < M; i++) {
		if (K > v[i]) continue;
		double tmp = 1;
		for (int j = 0; j < K; j++) tmp *= (v[i] - j) / (N - j);
		p += tmp;
	}
	cout << p;


	return 0;
}