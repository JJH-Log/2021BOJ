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

struct info {
	int power, idx;
};

bool compare(info a, info b) {
	return a.power < b.power;
}

int N, M, tidx;
int limit[100000];
string name[100000];
info v[100000];
string res[100000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> name[i] >> limit[i];
	for (int i = 0; i < M; i++) {
		v[i].idx = i;
		cin >> v[i].power;
	}
	sort(v, v + M, compare);
	for (int i = 0; i < M; i++) {
		while (v[i].power > limit[tidx]) tidx++;
		res[v[i].idx] = name[tidx];
	}
	for (int i = 0; i < M; i++) cout << res[i] << '\n';
	

	return 0;
}