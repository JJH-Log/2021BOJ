#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, result;
	int N, M;
	cin >> N >> M;
	v.resize(N + 1, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int idx = lower_bound(v.begin(), v.end(), 0) - v.begin();

	result = 0;
	for (int i = 0; i < idx; i += M) result -= 2 * v[i];
	for (int i = v.size() - 1; i > idx; i -= M) result += 2 * v[i];
	cout << result - max(abs(v[0]), v[v.size() - 1]);
	return 0;
}