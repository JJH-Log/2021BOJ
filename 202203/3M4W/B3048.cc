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

struct info {
	int way;
	char x;
};

int N, M, T;
string s;
info v[26];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < N; i++) v[i] = { 0, s[i] };
	cin >> s;
	for (int i = N; i < N + M; i++) v[i] = { 1, s[i - N] };

	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < N + M - 1; j++) {
			if (v[j].way == 0 && v[j + 1].way == 1) swap(v[j], v[j + 1]), j++;
		}
	}
	for (int i = 0; i < N + M; i++) cout << v[i].x;


	return 0;
}