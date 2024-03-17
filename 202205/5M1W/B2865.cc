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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, K;
int num;
double val, res;
map<int, double> m;
vector<double> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(1);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num >> val;
			if (!m.count(num)) m[num] = val;
			else m[num] = max(m[num], val);
		}
	}
	for (auto now : m) v.push_back(now.second);
	sort(v.begin(), v.end(), greater<double>());
	for (int i = 0; i < K; i++)  res += v[i];
	cout << res;

	return 0;
}
