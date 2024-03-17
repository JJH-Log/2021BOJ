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

int N, idx, lft, cnt;
int v[1000];
bool ans[1000];
vector<int> res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	idx = 0, lft = 0;

	while (res.size() < N) {
		while (lft) {
			if (lft < 0) {
				idx = (N + idx - 1) % N;
				if (!ans[idx]) lft++;
			}
			else {
				idx = (idx + 1) % N;
				if (!ans[idx]) lft--;
			}
		}
		ans[idx] = true;
		res.push_back(idx + 1);
		lft = v[idx];
	}
	for (auto r : res) cout << r << ' ';

	return 0;
}
