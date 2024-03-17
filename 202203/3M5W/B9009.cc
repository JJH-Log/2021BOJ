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

lld f[45];
stack<int> st;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	f[1] = 1;
	for (int i = 2; i <= 44; i++) f[i] = f[i - 1] + f[i - 2];
	
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		while (N) {
			int idx = upper_bound(f, f + 45, N) - f;
			st.push(f[idx - 1]);
			N -= f[idx - 1];
		}
		while (!st.empty()) {
			cout << st.top() << ' ';
			st.pop();
		}
		cout << '\n';
	}
	return 0;
}