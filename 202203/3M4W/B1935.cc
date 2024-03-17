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


int N, v[26];
string s;
stack<double> st;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2);
	cout << fixed;

	cin >> N >> s;
	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			st.push(v[s[i] - 'A']);
		}
		else {
			double y = st.top(); st.pop();
			double x = st.top(); st.pop();
			double ans;
			if (s[i] == '+') ans = x + y;
			if (s[i] == '-') ans = x - y;
			if (s[i] == '*') ans = x * y;
			if (s[i] == '/') ans = x / y;
			st.push(ans);
		}
	}
	cout << st.top();

	return 0;
}