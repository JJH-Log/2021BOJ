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

int N, M, x, before, f[41];
lld res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//일련의 K개 좌석 자리 배치 경우의 수 : 피보나치 수열
	f[0] = f[1] = 1;
	for (int i = 2; i <= 40; i++) f[i] = f[i - 1] + f[i - 2]; 

	cin >> N >> M;
	res = 1;
	int before = 0;
	for (int i = 0; i < M; i++) {
		cin >> x;
		res *= f[x - before - 1];
		before = x;
	}
	res *= f[N - before];
	cout << res;

	return 0;
}