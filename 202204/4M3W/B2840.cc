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

int N, K, t, ptr;
char tar;
bool ERR;
char v[25];
bool alpha[26];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	ERR = false;
	for (int i = 0; i < N; i++) v[i] = '?';
	ptr = 0;
	for (int i = 0; i < K; i++) {
		cin >> t >> tar;
		ptr = (ptr + t) % N;
		if (v[ptr] == '?') v[ptr] = tar;
		else if (v[ptr] != tar) ERR = true;
	}
	for (int i = 0; i < N; i++) {
		if (v[i] >= 'A' && v[i] <= 'Z') {
			if (alpha[v[i] - 'A']) ERR = true;
			else alpha[v[i] - 'A'] = true;
		}
	}

	if (ERR) cout << '!';
	else for (int i = 0; i < N; i++) cout << v[(ptr - i + N) % N];

	return 0;
}