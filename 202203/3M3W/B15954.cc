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
#define BOUND 2000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 5005
using namespace std;

double v[501];
double w[501];
int N, K;
double res;

double stdv(int s, int e) {
	double m, var;
	m = (w[e] - w[s - 1]) / K;
	var = 0;
	for (int i = s; i <= e; i++) var += (v[i] - m) * (v[i] - m);
	return sqrt(var / K);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(10);
	cout << fixed;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> v[i];
	for (int i = 1; i <= N; i++) w[i] = v[i] + w[i - 1];
	res = 1e9;

	for (; K <= N; K++) for (int i = 1; i + K - 1 <= N; i++) res = min(res, stdv(i, i + K - 1));
	
	cout << res;

	return 0;
}

