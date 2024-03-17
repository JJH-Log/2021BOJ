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
#define MOD 1000000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;


int v[300001], N;
vector<int> li;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, total;
	t = 0, total = 0;
	for (int i = 1; total <= 300001; i++) {
		t += i;
		total += t;
		if(total <= 300001) li.push_back(total);
	}
	fill(v, v + 300001, 1e9);
	for (auto c : li) v[c] = 1;

	for (int i = 1; i <= 300000; i++) {
		for (int j = 0; j < li.size() && i + li[j] <= 300000; j++) v[i + li[j]] = min(v[i + li[j]], v[i] + 1);
	}
	cin >> N;
	cout << v[N];


	return 0;
}