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


int N, res;
string v[50];
bool lock[50];

bool isSuffix(string x, string y){
	for (int i = 0; i < x.size(); i++) if (i == y.size() || x[i] != y[i]) return false;
	return true;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (lock[i] || lock[j]) continue;
			if (isSuffix(v[i], v[j])) lock[i] = true;
		}
	}
	for (int i = 0; i < N; i++) if (!lock[i]) res++;
	cout << res;

	return 0;
}