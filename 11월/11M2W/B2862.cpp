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
#include <sstream>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<lld> v;

lld ans(lld target) {
	int idx = lower_bound(v.begin(), v.end(), target) - v.begin();
	if (v[idx] == target) return target;
	else return ans(target - v[idx - 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld N, t1, t2;

	t1 = 1;
	t2 = 1;
	v.push_back(1);
	while (t1 <= 1e15) {
		t1 += t2;
		v.push_back(t1);
		swap(t1, t2);
	}
	cin >> N;
	cout << ans(N);

	return 0;
}
