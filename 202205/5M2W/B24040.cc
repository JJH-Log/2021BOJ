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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld T, N;
int rule[9] = { 0, 1, 0, 0, 1, 0, 0, 1, 1 };
/*
//implementation of bruteforce
void solve(int tar) {
	for (int i = 1; i * i <= tar; i++) {
		if (tar % i == 0) {
			if ((i + tar / i) % 3 == 0) {
				cout << tar << ' ' << "TAK\n";
				return;
			}
		}
	}
	cout << tar << ' ' << "NIE\n";
}
*/

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N; N--;
		if (rule[N % 9]) cout << "TAK\n";
		else cout << "NIE\n";
	}

	return 0;
}